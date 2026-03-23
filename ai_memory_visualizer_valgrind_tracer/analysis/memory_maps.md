# Memory Maps — AI Memory Visualizer

## Program 1: `recursive_sum.c`

### Source summary

Allocates one `int` on the heap, passes its value to a recursive function
that computes `n + (n-1) + ... + 1`, prints the result, then frees the
heap block.

---

### Key execution points

#### 1. Entry of `main` — stack frame created

```
STACK
┌─────────────────────────────┐
│ main frame                  │
│   heap_val : int* = ?       │  (uninitialized)
│   result   : int  = ?       │
└─────────────────────────────┘

HEAP
(empty)
```

#### 2. After `malloc(sizeof(int))`

```
STACK
┌─────────────────────────────┐
│ main frame                  │
│   heap_val : int* = 0x...A  │  ──────────────────┐
│   result   : int  = ?       │                    │
└─────────────────────────────┘                    ▼
                                            HEAP
                                            ┌──────────┐
                                            │ 0x...A   │
                                            │ int = ?  │  (uninitialized)
                                            └──────────┘
```

#### 3. After `*heap_val = 5`

```
HEAP
┌──────────┐
│ 0x...A   │
│ int = 5  │
└──────────┘
```

#### 4. During `recursive_sum(5)` — stack grows

Each recursive call pushes a new frame with its own `n`:

```
STACK (top → bottom)
┌─────────────────────┐
│ recursive_sum(0)    │  n=0, returns 0
├─────────────────────┤
│ recursive_sum(1)    │  n=1, returns 1+0 = 1
├─────────────────────┤
│ recursive_sum(2)    │  n=2, returns 2+1 = 3
├─────────────────────┤
│ recursive_sum(3)    │  n=3, returns 3+3 = 6
├─────────────────────┤
│ recursive_sum(4)    │  n=4, returns 4+6 = 10
├─────────────────────┤
│ recursive_sum(5)    │  n=5, returns 5+10 = 15
├─────────────────────┤
│ main                │  heap_val=0x...A, result=?
└─────────────────────┘
```

Each frame is **independent** — `n` in `recursive_sum(3)` has no relation
to `n` in `recursive_sum(5)`. They share no memory.

#### 5. After all returns — stack unwound

```
STACK
┌─────────────────────────────┐
│ main frame                  │
│   heap_val : int* = 0x...A  │
│   result   : int  = 15      │
└─────────────────────────────┘

HEAP
┌──────────┐
│ 0x...A   │
│ int = 5  │  (unchanged — recursive_sum only read *heap_val once)
└──────────┘
```

#### 6. After `free(heap_val)`

```
STACK
┌─────────────────────────────┐
│ main frame                  │
│   heap_val : int* = 0x...A  │  (dangling — address still held but block freed)
│   result   : int  = 15      │
└─────────────────────────────┘

HEAP
(block at 0x...A is freed — accessing it is undefined behavior)
```

**Lifetime**: the heap block lives from `malloc` to `free`.
`heap_val` itself lives on the stack for the entire duration of `main`.

---

## Program 2: `pointer_alias.c`

### Source summary

`main` declares a stack array `original[]`, passes it to `clone_and_modify`
which allocates a heap copy, changes the first byte, and returns the pointer.
`main` then frees it.

---

### Key execution points

#### 1. Entry of `main`

```
STACK
┌──────────────────────────────────┐
│ main frame                       │
│   original[6] = {'H','e','l',    │  (stack array, 6 bytes including \0)
│                  'l','o','\0'}   │
│   modified : char* = ?           │
└──────────────────────────────────┘

HEAP
(empty)
```

`original` is a **stack array**, not a pointer. Its address is stable for
the lifetime of `main`.

#### 2. Inside `clone_and_modify` — after `malloc`

```
STACK
┌──────────────────────────────────┐
│ clone_and_modify frame           │
│   src  : char* = &original[0]   │  ──┐ alias to stack
│   copy : char* = 0x...B         │    │
└──────────────────────────────────┤    │
│ main frame                       │    │
│   original[6] at 0x...S          │ ◄──┘
│   modified : char* = ?           │
└──────────────────────────────────┘

HEAP
┌───────────────────────────┐
│ 0x...B  char[6] = "Hello" │  (freshly copied)
└───────────────────────────┘
```

`src` and `&original[0]` are **aliases** — two pointers to the same stack
memory. Modifying through `src` would modify `original`.

#### 3. After `copy[0] = 'X'`

```
HEAP
┌───────────────────────────┐
│ 0x...B  char[6] = "Xello" │
└───────────────────────────┘

STACK original[] = "Hello"  (unchanged — copy is independent)
```

#### 4. Back in `main` after `free(modified)`

```
STACK
┌──────────────────────────────────┐
│ main frame                       │
│   original[6] = "Hello"          │  (stack — still valid)
│   modified : char* = 0x...B      │  (dangling — heap block freed)
└──────────────────────────────────┘
```

**Variable lifetimes**:
- `original[]` : lives on the stack from entry to exit of `main`
- `copy` (heap) : lives from `malloc` inside `clone_and_modify` to `free` in `main`
- `src` (parameter) : lives only during `clone_and_modify` execution

---

## Ownership Summary

| Object | Allocated by | Owned by | Must be freed by |
|---|---|---|---|
| `heap_val` block | `malloc` in `main` | `main` | `main` — done ✓ |
| `copy` block | `malloc` in `clone_and_modify` | transferred to `main` via return value | `main` — done ✓ |
| `original[]` | stack (automatic) | `main` stack frame | automatic at function return |
| `src` parameter | stack (automatic) | `clone_and_modify` frame | automatic at function return |

**Rule**: whoever holds the last pointer to a heap block is responsible
for calling `free`. Returning a heap pointer transfers ownership to the
caller.

---

## AI Correction Log

### Error found in AI-generated explanation

**AI claim**: *"After `free(heap_val)`, `heap_val` is set to NULL automatically."*

**Why it is wrong**:
`free()` releases the heap block but does **not** modify the pointer
variable itself. `heap_val` still holds the address `0x...A` after
`free(heap_val)`. It is a **dangling pointer** — the address is still
there, but the memory it points to is no longer owned by the program.
Accessing `*heap_val` after `free` is undefined behavior, not a null
dereference.

**Correction**:
To safely avoid dangling pointers, the programmer must manually set
`heap_val = NULL` after calling `free`. This is a convention, not
something C does automatically.

---

### Second error found

**AI claim**: *"In `clone_and_modify`, `src` is a copy of the string `original`."*

**Why it is wrong**:
`src` is a `char *` parameter — it receives the **address** of
`original[0]`, not a copy of the string contents. The string data
remains on the stack inside `main`. `src` and `&original[0]` are
aliases pointing to the same memory. Only after `strcpy(copy, src)`
is a real independent copy created on the heap.

**Correction**:
A pointer parameter copies the address, not the data. To copy data,
an explicit operation like `strcpy` or `memcpy` is required.

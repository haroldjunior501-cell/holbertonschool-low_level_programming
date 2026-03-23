CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu89

all: recursive_sum pointer_alias memory_errors

recursive_sum: programs/recursive_sum.c
	$(CC) $(CFLAGS) programs/recursive_sum.c -o programs/recursive_sum

pointer_alias: programs/pointer_alias.c
	$(CC) $(CFLAGS) programs/pointer_alias.c -o programs/pointer_alias

memory_errors: programs/memory_errors.c
	$(CC) -g programs/memory_errors.c -o programs/memory_errors

clean:
	rm -f programs/recursive_sum programs/pointer_alias programs/memory_errors

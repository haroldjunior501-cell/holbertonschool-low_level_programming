#include <stdio.h>
#include <stdlib.h>

int recursive_sum(int n)
{
	if (n <= 0)
		return (0);
	return (n + recursive_sum(n - 1));
}

int main(void)
{
	int *heap_val;
	int result;

	heap_val = malloc(sizeof(int));
	*heap_val = 5;
	result = recursive_sum(*heap_val);
	printf("Sum: %d\n", result);
	free(heap_val);
	return (0);
}

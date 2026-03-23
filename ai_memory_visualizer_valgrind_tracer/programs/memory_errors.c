#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *leak;
	int *uaf;
	int *uninit;
	int val;

	leak = malloc(sizeof(int) * 10);
	leak[0] = 42;

	uaf = malloc(sizeof(int));
	*uaf = 99;
	free(uaf);
	val = *uaf;
	printf("use-after-free: %d\n", val);

	uninit = malloc(sizeof(int));
	if (*uninit > 0)
		printf("uninitialized read\n");
	free(uninit);

	return (0);
}

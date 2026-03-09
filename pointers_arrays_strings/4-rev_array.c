#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: pointer to the array
 * @n: number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int i;
	int end;
	int tmp;

	i = 0;
	end = n - 1;
	while (i < end)
	{
		tmp = a[i];
		a[i] = a[end];
		a[end] = tmp;
		i++;
		end--;
	}
}

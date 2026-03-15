#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	int step;

	step = (n <= 98) ? 1 : -1;
	while (n != 98)
	{
		printf("%d, ", n);
		n += step;
	}
	printf("%d\n", 98);
}

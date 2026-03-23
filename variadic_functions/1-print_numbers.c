#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a string
 * @separator: the string to print between numbers
 * @n: the number of integers
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		if (i > 0 && separator != NULL)
			printf("%s", separator);
		printf("%d", va_arg(args, int));
		i++;
	}
	va_end(args);
	printf("\n");
}

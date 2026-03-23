#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a string
 * @separator: the string to print between strings
 * @n: the number of strings
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		if (i > 0 && separator != NULL)
			printf("%s", separator);
		str = va_arg(args, char *);
		printf("%s", str ? str : "(nil)");
		i++;
	}
	va_end(args);
	printf("\n");
}

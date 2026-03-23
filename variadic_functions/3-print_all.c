#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_one - prints one argument based on type
 * @args: the va_list
 * @c: the type character
 *
 * Return: 1 if printed, 0 otherwise
 */
static int print_one(va_list args, char c)
{
	char *str;

	if (c == 'c')
	{
		printf("%c", va_arg(args, int));
		return (1);
	}
	if (c == 'i')
	{
		printf("%d", va_arg(args, int));
		return (1);
	}
	if (c == 'f')
	{
		printf("%f", (float)va_arg(args, double));
		return (1);
	}
	if (c == 's')
	{
		str = va_arg(args, char *);
		printf("%s", str ? str : "(nil)");
		return (1);
	}
	return (0);
}

/**
 * print_all - prints anything based on a format string
 * @format: list of types (c, i, f, s)
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	int sep;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format != NULL && format[i])
	{
		if (sep && (format[i] == 'c' || format[i] == 'i' ||
			format[i] == 'f' || format[i] == 's'))
			printf(", ");
		sep = print_one(args, format[i]);
		i++;
	}
	va_end(args);
	printf("\n");
}

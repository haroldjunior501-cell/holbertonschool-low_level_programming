#include <stdio.h>
#include "variadic_functions.h"

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
	char c;
	int integer;
	float f;
	char *str;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format != NULL && format[i])
	{
		c = format[i];
		str = NULL;
		if (c == 'c')
		{
			integer = va_arg(args, int);
			if (sep)
				printf(", ");
			printf("%c", integer);
			sep = 1;
		}
		if (c == 'i')
		{
			integer = va_arg(args, int);
			if (sep)
				printf(", ");
			printf("%d", integer);
			sep = 1;
		}
		if (c == 'f')
		{
			f = (float)va_arg(args, double);
			if (sep)
				printf(", ");
			printf("%f", f);
			sep = 1;
		}
		if (c == 's')
		{
			str = va_arg(args, char *);
			if (sep)
				printf(", ");
			printf("%s", str ? str : "(nil)");
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}

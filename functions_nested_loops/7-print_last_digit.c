#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int last;

	if (n < 0)
		last = -(n % 10);
	else
		last = n % 10;
	_putchar('0' + last);
	return (last);
}

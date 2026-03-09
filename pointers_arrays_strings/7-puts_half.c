#include "main.h"

/**
 * puts_half - prints the second half of a string followed by a new line
 * @str: pointer to the string to print
 */
void puts_half(char *str)
{
	int len;
	int start;

	len = 0;
	while (str[len] != '\0')
		len++;
	start = (len + 1) / 2;
	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}
	_putchar('\n');
}

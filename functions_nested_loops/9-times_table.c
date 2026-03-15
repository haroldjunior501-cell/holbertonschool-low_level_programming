#include "main.h"

/**
 * times_table - prints the 9 times table starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int i;
	int j;
	int product;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 9)
		{
			product = i * j;
			if (j == 0)
			{
				_putchar('0' + product);
			}
			else
			{
				_putchar(',');
				if (product < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar('0' + product);
				}
				else
				{
					_putchar(' ');
					_putchar('0' + product / 10);
					_putchar('0' + product % 10);
				}
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}

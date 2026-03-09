#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int num;
	int neg_count;

	i = 0;
	sign = 1;
	num = 0;
	neg_count = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			neg_count++;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (neg_count % 2 != 0)
				sign = -1;
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			return (sign * num);
		}
		i++;
	}
	return (0);
}

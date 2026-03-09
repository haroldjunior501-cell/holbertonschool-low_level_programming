#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to reverse
 */
void rev_string(char *s)
{
	int len;
	int i;
	char tmp;

	len = 0;
	while (s[len] != '\0')
		len++;
	len--;
	i = 0;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
}

#include "main.h"

/**
 * string_toupper - changes all lowercase letters to uppercase
 * @s: pointer to the string to modify
 *
 * Return: pointer to the modified string
 */
char *string_toupper(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}

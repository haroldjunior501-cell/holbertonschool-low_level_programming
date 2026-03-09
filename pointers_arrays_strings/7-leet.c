#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i;
	int j;
	char from[] = "aAeEoOtTlL";
	char to[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (from[j] != '\0')
		{
			if (s[i] == from[j])
				s[i] = to[j];
			j++;
		}
		i++;
	}
	return (s);
}

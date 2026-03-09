#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: pointer to the string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i;
	int sep;

	i = 0;
	sep = 1;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
			s[i] == ',' || s[i] == ';' || s[i] == '.' ||
			s[i] == '!' || s[i] == '?' || s[i] == '"' ||
			s[i] == '(' || s[i] == ')' || s[i] == '{' ||
			s[i] == '}')
			sep = 1;
		else if (sep == 1)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 32;
			sep = 0;
		}
		i++;
	}
	return (s);
}

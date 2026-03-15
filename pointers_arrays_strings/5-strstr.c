#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring in a string
 * @haystack: the string to search in
 * @needle: the substring to find
 *
 * Return: pointer to the beginning of the substring, or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return (haystack + i);
		i++;
	}
	return (NULL);
}

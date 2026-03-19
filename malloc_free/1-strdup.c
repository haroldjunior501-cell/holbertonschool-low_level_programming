#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: the string to duplicate
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup;
	int len;
	int i;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *clone_and_modify(char *src)
{
	char *copy;

	copy = malloc(strlen(src) + 1);
	if (copy == NULL)
		return (NULL);
	strcpy(copy, src);
	copy[0] = 'X';
	return (copy);
}

int main(void)
{
	char original[] = "Hello";
	char *modified;

	modified = clone_and_modify(original);
	printf("original: %s\n", original);
	printf("modified: %s\n", modified);
	free(modified);
	return (0);
}

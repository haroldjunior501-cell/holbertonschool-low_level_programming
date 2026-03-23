#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_suffix(char *str)
{
	int len;

	len = strlen(str);
	return (str + len + 1);
}

int main(void)
{
	char *words[3];
	char *result;
	int i;

	words[0] = strdup("Hello");
	words[1] = strdup("World");
	words[2] = NULL;

	i = 0;
	while (i <= 3)
	{
		result = get_suffix(words[i]);
		printf("suffix of words[%d]: %s\n", i, result);
		i++;
	}

	free(words[0]);
	free(words[1]);
	return (0);
}

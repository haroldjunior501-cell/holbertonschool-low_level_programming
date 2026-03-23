#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int n;
	int i;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	ptr = (unsigned char *)main;
	i = 0;
	while (i < n)
	{
		if (i > 0)
			printf(" ");
		printf("%02x", ptr[i]);
		i++;
	}
	printf("\n");
	return (0);
}

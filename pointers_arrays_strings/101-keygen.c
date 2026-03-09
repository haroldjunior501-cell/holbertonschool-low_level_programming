#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
	int target;
	int i;
	int val;

	srand(time(NULL));
	target = 0xad4;

	while (target > 0)
	{
		if (target >= 126)
			val = 33 + rand() % 94;
		else if (target >= 33)
			val = target;
		else
			val = target;
		putchar(val);
		target -= val;
		i++;
	}
	return (0);
}

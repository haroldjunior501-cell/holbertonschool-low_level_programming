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
	int len;
	int i;
	int val;
	int remaining;

	srand(time(NULL));
	target = 0xad4;
	len = 10 + rand() % 10;

	for (i = 0; i < len - 1; i++)
	{
		remaining = target - (len - 1 - i) * 33;
		if (remaining > 126)
			val = 33 + rand() % 94;
		else
			val = remaining;
		putchar(val);
		target -= val;
	}
	putchar(target);
	return (0);
}

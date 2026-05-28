#include "main.h"

/**
 * prime_helper - checks divisibility from divisor i up to sqrt(n)
 * @n: the number to test
 * @i: current divisor candidate
 *
 * Return: 1 if no divisor found (prime), 0 if divisible
 */
int prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: the number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_helper(n, 2));
}

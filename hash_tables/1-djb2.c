#include "hash_tables.h"

/**
 * hash_djb2 - implements the djb2 hash algorithm
 * @str: the string to hash
 *
 * Return: the hash value of the string
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}

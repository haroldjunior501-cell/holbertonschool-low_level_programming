#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - node of a hash table
 * @key: the key (string)
 * @value: the value (string)
 * @next: pointer to the next node (chaining for collisions)
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - hash table
 * @size: the size of the array
 * @array: array of pointers to linked lists of hash_node_t
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

#endif /* HASH_TABLES_H */

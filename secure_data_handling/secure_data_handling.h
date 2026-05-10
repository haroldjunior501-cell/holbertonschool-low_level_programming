#ifndef SECURE_DATA_HANDLING_H
#define SECURE_DATA_HANDLING_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct session_s - holds a session id and its associated data
 * @id: unique session identifier
 * @data: session payload
 */
typedef struct session_s
{
	char *id;
	char *data;
} session_t;

/**
 * struct store_node_s - node in the store linked list
 * @session: pointer to the stored session
 * @next: pointer to the next node
 */
typedef struct store_node_s
{
	session_t *session;
	struct store_node_s *next;
} store_node_t;

/**
 * struct store_s - session store
 * @head: pointer to the first node
 * @count: number of sessions currently stored
 */
typedef struct store_s
{
	store_node_t *head;
	size_t count;
} store_t;

/* session.c */
session_t *session_create(const char *id, const char *data);
int        session_update(session_t *s, const char *data);
void       session_clear(session_t *s);
void       session_destroy(session_t *s);

/* store.c */
store_t   *store_create(void);
int        store_insert(store_t *store, session_t *session);
session_t *store_get(store_t *store, const char *id);
int        store_delete(store_t *store, const char *id);
void       store_clear(store_t *store);
void       store_destroy(store_t *store);

#endif /* SECURE_DATA_HANDLING_H */

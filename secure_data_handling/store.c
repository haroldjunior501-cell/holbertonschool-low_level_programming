#include <stdlib.h>
#include <string.h>
#include "session.h"
#include "store.h"

/**
 * store_init - initialises an already-allocated store struct
 * @store: pointer to the store to initialise
 */
void store_init(store_t *store)
{
	if (store == NULL)
		return;

	store->head = NULL;
}

/**
 * store_create - allocates and initialises a new store
 *
 * Return: pointer to new store, or NULL on failure
 */
store_t *store_create(void)
{
	store_t *store;

	store = malloc(sizeof(store_t));
	if (store == NULL)
		return (NULL);

	store_init(store);

	return (store);
}

/**
 * store_add - inserts a session into the store
 * @store: the session store
 * @session: the session to add
 *
 * Return: 0 on success, -1 if duplicate id or invalid args
 */
int store_add(store_t *store, session_t *session)
{
	node_t *node;
	node_t *current;

	if (store == NULL || session == NULL || session->id == NULL)
		return (-1);

	current = store->head;
	while (current != NULL)
	{
		if (strcmp(current->sess->id, session->id) == 0)
			return (-1);
		current = current->next;
	}

	node = malloc(sizeof(node_t));
	if (node == NULL)
		return (-1);

	node->sess = session;
	node->next = store->head;
	store->head = node;

	return (1);
}

/**
 * store_get - retrieves a session by its id
 * @store: the session store
 * @id: the session id to look up
 *
 * Return: pointer to the session, or NULL if not found
 */
session_t *store_get(store_t *store, const char *id)
{
	node_t *current;

	if (store == NULL || id == NULL || *id == '\0')
		return (NULL);

	current = store->head;
	while (current != NULL)
	{
		if (strcmp(current->sess->id, id) == 0)
			return (current->sess);
		current = current->next;
	}

	return (NULL);
}

/**
 * store_delete - removes a session by id, transferring ownership to caller
 * @st: the session store
 * @id: the session id to delete
 * @out: receives the session if non-NULL, otherwise session is destroyed
 *
 * Return: 0 on success, -1 if not found or invalid args
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *current;
	node_t *prev;

	if (out != NULL)
		*out = NULL;

	if (st == NULL || id == NULL || *id == '\0')
		return (-1);

	current = st->head;
	prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->sess->id, id) == 0)
		{
			if (prev == NULL)
				st->head = current->next;
			else
				prev->next = current->next;
			if (out != NULL)
				*out = current->sess;
			else
				session_destroy(current->sess);
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}

	return (-1);
}

/**
 * store_clear - destroys all sessions, leaving the store reusable
 * @store: the session store to clear
 */
void store_clear(store_t *store)
{
	node_t *current;
	node_t *next;

	if (store == NULL)
		return;

	current = store->head;
	while (current != NULL)
	{
		next = current->next;
		session_destroy(current->sess);
		free(current);
		current = next;
	}

	store->head = NULL;
}

/**
 * store_destroy - clears all sessions in the store
 * @store: the session store to destroy
 */
void store_destroy(store_t *store)
{
	store_clear(store);
}

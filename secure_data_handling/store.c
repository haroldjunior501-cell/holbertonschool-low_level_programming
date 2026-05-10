#include "session.h"
#include "store.h"

/**
 * store_create - allocates an empty session store
 *
 * Return: pointer to new store, or NULL on failure
 */
store_t *store_create(void)
{
	store_t *store;

	store = malloc(sizeof(store_t));
	if (store == NULL)
		return (NULL);

	store->head = NULL;
	store->count = 0;

	return (store);
}

/**
 * store_insert - inserts a session into the store
 * @store: the session store
 * @session: the session to insert
 *
 * Return: 0 on success, -1 if duplicate id or invalid args
 */
int store_insert(store_t *store, session_t *session)
{
	store_node_t *node;
	store_node_t *current;

	if (store == NULL || session == NULL || session->id == NULL)
		return (-1);

	current = store->head;
	while (current != NULL)
	{
		if (strcmp(current->session->id, session->id) == 0)
			return (-1);
		current = current->next;
	}

	node = malloc(sizeof(store_node_t));
	if (node == NULL)
		return (-1);

	node->session = session;
	node->next = store->head;
	store->head = node;
	store->count++;

	return (0);
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
	store_node_t *current;

	if (store == NULL || id == NULL || *id == '\0')
		return (NULL);

	current = store->head;
	while (current != NULL)
	{
		if (strcmp(current->session->id, id) == 0)
			return (current->session);
		current = current->next;
	}

	return (NULL);
}

/**
 * store_delete - removes and destroys the session with the given id
 * @store: the session store
 * @id: the session id to delete
 *
 * Return: 0 on success, -1 if not found or invalid args
 */
int store_delete(store_t *store, const char *id)
{
	store_node_t *current;
	store_node_t *prev;

	if (store == NULL || id == NULL || *id == '\0')
		return (-1);

	current = store->head;
	prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->session->id, id) == 0)
		{
			if (prev == NULL)
				store->head = current->next;
			else
				prev->next = current->next;
			session_destroy(current->session);
			free(current);
			store->count--;
			return (0);
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
	store_node_t *current;
	store_node_t *next;

	if (store == NULL)
		return;

	current = store->head;
	while (current != NULL)
	{
		next = current->next;
		session_destroy(current->session);
		free(current);
		current = next;
	}

	store->head = NULL;
	store->count = 0;
}

/**
 * store_destroy - frees all sessions and the store itself
 * @store: the session store to destroy
 */
void store_destroy(store_t *store)
{
	if (store == NULL)
		return;

	store_clear(store);
	free(store);
}

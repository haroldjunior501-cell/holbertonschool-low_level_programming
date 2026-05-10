#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - allocates and initialises a new session
 * @id: unique session identifier (duplicated)
 * @data: session payload (duplicated, may be empty string)
 *
 * Return: pointer to new session, or NULL on failure
 */
session_t *session_create(const char *id, const char *data)
{
	session_t *s;

	if (id == NULL || *id == '\0' || data == NULL)
		return (NULL);

	s = malloc(sizeof(session_t));
	if (s == NULL)
		return (NULL);

	s->id = strdup(id);
	if (s->id == NULL)
	{
		free(s);
		return (NULL);
	}

	s->data = strdup(data);
	if (s->data == NULL)
	{
		free(s->id);
		free(s);
		return (NULL);
	}

	return (s);
}

/**
 * session_update - replaces the data payload of a session
 * @s: the session to update
 * @data: new data string (duplicated)
 *
 * Return: 0 on success, -1 on failure
 */
int session_update(session_t *s, const char *data)
{
	char *new_data;

	if (s == NULL || data == NULL)
		return (-1);

	new_data = strdup(data);
	if (new_data == NULL)
		return (-1);

	free(s->data);
	s->data = new_data;

	return (0);
}

/**
 * session_clear - frees the data payload and sets it to NULL
 * @s: the session whose data should be cleared
 */
void session_clear(session_t *s)
{
	if (s == NULL)
		return;

	free(s->data);
	s->data = NULL;
}

/**
 * session_destroy - fully frees a session and its fields
 * @s: the session to destroy
 */
void session_destroy(session_t *s)
{
	if (s == NULL)
		return;

	free(s->id);
	free(s->data);
	free(s);
}

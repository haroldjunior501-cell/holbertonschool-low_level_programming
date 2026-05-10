#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - allocates and initialises a new session
 * @id: unique session identifier (duplicated)
 * @uid: user id associated with the session
 * @data: session payload (duplicated)
 * @data_len: length of the data payload
 *
 * Return: pointer to new session, or NULL on failure
 */
session_t *session_create(const char *id, unsigned int uid,
		const unsigned char *data, size_t data_len)
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

	s->data = malloc(data_len);
	if (s->data == NULL)
	{
		free(s->id);
		free(s);
		return (NULL);
	}

	memcpy(s->data, data, data_len);
	s->uid = uid;
	s->data_len = data_len;

	return (s);
}

/**
 * session_update - replaces the data payload of a session
 * @s: the session to update
 * @data: new data (duplicated)
 * @data_len: length of the new data
 *
 * Return: 0 on success, -1 on failure
 */
int session_update(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *new_data;

	if (s == NULL || data == NULL)
		return (-1);

	new_data = malloc(data_len);
	if (new_data == NULL)
		return (-1);

	memcpy(new_data, data, data_len);
	free(s->data);
	s->data = new_data;
	s->data_len = data_len;

	return (0);
}

/**
 * session_clear - frees the data payload and zeroes related fields
 * @s: the session whose data should be cleared
 */
void session_clear(session_t *s)
{
	if (s == NULL)
		return;

	free(s->data);
	s->data = NULL;
	s->data_len = 0;
}

/**
 * session_set_data - replaces session data (alias for session_update)
 * @s: the session to update
 * @data: new data payload
 * @data_len: length of the new data
 *
 * Return: 0 on success, -1 on failure
 */
int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	return (session_update(s, data, data_len));
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

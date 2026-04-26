#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: head of the list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

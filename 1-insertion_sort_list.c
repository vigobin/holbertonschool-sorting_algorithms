#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *  order using the Insertion sort algorithm.
 * @list: doulbly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	listint_t *marker = NULL;

	if ((*list)->next == NULL || !list || !(*list))
		return;

	temp = *list;
	marker = *list;

	while (marker)
	{
		marker = marker->next;

		while (temp->prev && (temp->n < temp->prev->n))
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next->prev = temp;
			print_list(*list);
		}
		temp = marker;
	}
}

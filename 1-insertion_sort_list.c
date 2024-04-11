#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in
*                       ascending order using the Insertion sort algorithm.
* @list: A pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !((*list)->next))
	{
		return;
	}

	listint_t *current = (*list)->next;

	while (current)
	{
		listint_t *tmp = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next)
			{
				current->next->prev = current->prev;
			}

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev)
			{
				current->prev->next = current;
			}

			else
			{
				*list = current;
			}

			print_list(*list);
		}

		current = tmp;
	}
}

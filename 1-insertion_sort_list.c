#include "sort.h"

/**
* swap_nodes - a
* @list: a
* @node1: a
* @node2: a
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!list || !node1 || !node2)
	{
		return;
	}

	if (node1->prev)
	{
		node1->prev->next = node2;
	}

	if (node2->next)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (!node2->prev)
	{
		*list = node2;
	}

}

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
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		current = tmp;
	}
}

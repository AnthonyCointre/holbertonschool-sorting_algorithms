#include "sort.h"

/**
* swap_node - function that swaps two nodes of a doubly linked list
*
* @list: pointer to the pointer of the head of the list
* @node: pointer to the node to swap
*
* Return: void
*/
void swap_node(listint_t **list, listint_t *node)
{
	node->prev->next = node->next;

	if (node->next != NULL)
	{
		node->next->prev = node->prev;
	}

	node->next = node->prev;
	node->prev = node->next->prev;
	node->next->prev = node;

	if (node->prev == NULL)
	{
		*list = node;
	}

	else
	{
		node->prev->next = node;
	}
}


/**
* insertion_sort_list - Sorts a dounode2ly linked list of integers in ascending
*                       order using the Insertion sort algorithm.
* @list: A pointer to the first element of the list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (current->next != NULL)
	{
		current = current->next;

		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_node(list, current);
			print_list(*list);
		}
	}
}

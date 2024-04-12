#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order
*               using the Bubble sort algorithm.
* @array: A pointer to the array to sort.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	int temp;

	size_t outer_index, inner_index;

	for (outer_index = 0; outer_index < size - 1; ++outer_index)
	{
		for (inner_index = 0; inner_index < size - outer_index - 1; ++inner_index)
		{
			if (array[inner_index] > array[inner_index + 1])
			{
				temp = array[inner_index];
				array[inner_index] = array[inner_index + 1];
				array[inner_index + 1] = temp;

				print_array(array, size);
			}
		}
	}
}

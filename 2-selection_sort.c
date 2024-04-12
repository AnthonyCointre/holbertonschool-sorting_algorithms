#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: A pointer to the array to sort.
 * @size: The number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_i;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_i = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_i])
				min_i = j;
		}

		if (min_i != i)
		{
			temp = array[i];
			array[i] = array[min_i];
			array[min_i] = temp;

			print_array(array, size);
		}
	}
}

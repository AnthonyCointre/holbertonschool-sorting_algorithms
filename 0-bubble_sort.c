#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order
*               using the Bubble sort algorithm.
* @array: The array to sort.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t step = 0, i = 0;
	int temp = 0;

	for (step = 0; step < size - 1; step++)
	{
		for (i = 0; i < size - step - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

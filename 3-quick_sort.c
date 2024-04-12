#include "sort.h"

/**
* swap - Swaps two elements of a array.
* @a: The first element.
* @b: The second element.
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* partition - Partitions an array around a pivot element.
 * @array: A pointer to the array to partition.
 * @low: The index of the first element of the array.
 * @high: The index of the last element of the array.
 * @size: The number of elements in the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = (low - 1);

	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j && array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high && array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
* quick_sort_rec - Sorts an array of integers in ascending order
*                  using the Quick sort algorithm
 * @array: A pointer to the array to be sorted.
 * @low: The index of the first element of the array.
 * @high: The index of the last element of the array.
 * @size: The number of elements in the array.
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		quick_sort_rec(array, low, i - 1, size);
		quick_sort_rec(array, i + 1, high, size);
	}
}

/**
* quick_sort - Trie un tableau d'entiers ordre croissant.
* @array: le tableau
* @size: taille du tableau
* Return: rien.
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

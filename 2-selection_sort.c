#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *  using the Selection sort algorithm.
 * @array: array to sort.
 * @size: size of array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t index;
	size_t lowest_index;
	int compare;
	int temp;

	for (i = 0; i < size; i++)
	{
		compare = array[i];
		for (index = i; index < size; index++)
		{
			if (compare > array[index])
			{
				compare = array[index];
				lowest_index = index;
			}
		}

		temp = array[i];
		if (temp != compare)
		{
			array[i] = array[lowest_index];
			array[lowest_index] = temp;
			print_array(array, size);
		}
	}
}

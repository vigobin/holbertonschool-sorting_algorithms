#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *  using the Bubble sort algorithm.
 * @array: input array.
 * @size: size of array.
 */

void bubble_sort(int *array, size_t size)
{
	int sort = 1;
	size_t i;

	if (!array)
		return;

	while (sort == 1)
	{
		sort = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				array[i] += array[i + 1];
				array[i + 1] = array[i] - array[i + 1];
				array[i] -= array[i + 1];
				print_array(array, size);
				sort = 1;
			}
		}
	}
}

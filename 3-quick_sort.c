#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *  using the Quick sort algorithm.
 * @array: array input.
 * @size: size of array.
 */

void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	partition(array,  0, size - 1, size);
}

/**
 * lomuto_sort - uses lomuto partition to sort an array.
 * @array: the array to sort.
 * @size: size of array;
 * @low_point: the lowest point in the array to start.
 * @high_point: the highest point in the array to go to.
 * Return: where the pivot ends up being placed at the end.
 */

int lomuto_sort(int *array, int low_point, int high_point, size_t size)
{
	int hold;
	int search;
	int pivot;

	hold = low_point - 1;
	search = low_point;
	pivot = high_point;

	while (search != pivot)
	{
		if (array[search] < array[pivot])
		{
			hold++;
			if (search != hold)
				swap_func(array, search, hold, size);
		}
		search++;
	}
	hold++;
	if (array[hold] > array[pivot])
		swap_func(array, hold, pivot, size);

	return (hold);
}

/**
 * partition - sets the sections to be looked through and passes them.
 * @array: the array to sort.
 * @low_point: the lowest point in the array to start at.
 * @high_point: the highest point in the array to go to.
 * @size: the size of the array.
 */

void partition(int *array, int low_point, int high_point, size_t size)
{
	int low_ended_at;

	if (low_point < high_point)
	{
		low_ended_at = lomuto_sort(array, low_point, high_point, size);
		partition(array, low_point, (low_ended_at - 1), size);
		partition(array, (low_ended_at + 1), high_point, size);
	}
}

/**
 * swap_func - swaps 2 numbers in the array.
 * @array: the array to sort.
 * @number1: the first position in the array to swap.
 * @number2: the second position in the array to swap.
 * @size: the size of the array.
 */

void swap_func(int *array, int number1, int number2, size_t size)
{
	int temp;

	temp = array[number1];
	array[number1] = array[number2];
	array[number2] = temp;
	print_array(array, size);
}

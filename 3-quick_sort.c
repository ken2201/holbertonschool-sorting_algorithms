#include "sort.h"

int lomuto_partition_scheme(int *array, int low, int high);
void swap(int *a, int *b);
void quick_sort_alg(int *array, int low, int high);
size_t get_size(int *array);

/**
 * quick_sort - function that sort with quick sort method
 * @array: the array to be sorted
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_alg(array, 0, size - 1);
}

/**
 * quick_sort - function that sort with quick sort method
 * @array: the array to be sorted
 * @high: the last index
 * @low: the first index
 */
void quick_sort_alg(int *array, int low, int high)
{
	int pivot_index = 0;

	if (low < high)
	{
		pivot_index = lomuto_partition_scheme(array, low, high);

		quick_sort_alg(array, low, pivot_index - 1);
		quick_sort_alg(array, pivot_index + 1, high);
	}
}

/**
 * lomuto_partion_scheme - lomuto partition of quick sorting
 * @array: an array to be sorted
 * @high: last index of the partition
 * @low: first index of partition
 * Return: the pivot index
 */
int lomuto_partition_scheme(int *array, int low, int high)
{
	int i, j, pivot;

	pivot = *(array + high);
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (*(array + j) < pivot)
		{
			i++;
			swap((array + j), (array + i));
		}
	}
	swap((array + high), (array + i + 1));
	return (i + 1);
}

/**
 * swap - swaps to int value
 * @a: integer address
 * @b: integer address
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

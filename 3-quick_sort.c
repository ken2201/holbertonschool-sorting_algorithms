#include "sort.h"

void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursively sorts the partitioned array
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	if (low >= high || low < 0)
		return;

	pivot = lomuto_partition(array, low, high, size);

	quicksort_recursive(array, low, pivot - 1, size);
	quicksort_recursive(array, pivot + 1, high, size);
}

/**
 * lomuto_partition - Implements Lomuto partition scheme
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


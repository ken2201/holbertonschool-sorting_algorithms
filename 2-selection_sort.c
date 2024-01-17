#include "sort.h"

/**
 * selection_sort - an algorithm that sort the given array by selection
 * method
 * @array: unsorted array of int to sort in ascending order
 * @size: the size of @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if ((array + i) == NULL || (array + j) == NULL)
				return;

			if (*(array + j) < *(array + min))
			{
				min = j;
				continue;
			}
		}

		if (min != i)
		{
			tmp = *(array + i);
			*(array + i) = *(array + min);
			*(array + min) = tmp;
			print_array(array, size);
		}
	}
}

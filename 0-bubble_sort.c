#include "sort.h"


/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * This function takes two integer pointers as parameters and swaps the
 * values of the integers they point to.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order usingBubble Sort
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * This function implements the Bubble Sort algorithm to arrange the elements
 * of the array in ascending order. It prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);

				for (size_t k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}
	}
}


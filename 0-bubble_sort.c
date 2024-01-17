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
	size_t i = 0, j = 0, k = 0;

	while (i < size - 1)
	{
		if (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);


				while (k < size)
				{
					printf("%d", array[k]);
					if (k < size - 1)
					{
						printf(", ");
					}
					k++;
				}
				printf("\n");
			}
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
}



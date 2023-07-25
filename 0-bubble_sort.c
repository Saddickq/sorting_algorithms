#include "sort.h"
/**
 * bubble_sort - a function that sort an array of integers
 * using the bubble sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;

	while (i < (size - 1))
	{
		for (j = 0; j < (size - 1) - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}

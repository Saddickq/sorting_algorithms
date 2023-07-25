#include "sort.h"
/**
 * selection_sort - A function that sorts an array of numbers
 * using the selection sort algorithm
 *
 * @array: The array to sort
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t temp, min, j, i = 0;

	if (size == 0 || !array)
		return;

	while (i < (size - 1))
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		i++;
	}
}

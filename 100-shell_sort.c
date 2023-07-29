#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap *= 3 + 1;

	while (gap > 0)
	{
		i = gap;

		while (i < size)
		{
			if (array[i] < array[i - gap])
			{
				temp = array[i];
				array[i] = array[i - gap];
				array[i - gap] = temp;
			}

			i++;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

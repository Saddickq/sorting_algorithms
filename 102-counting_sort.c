#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = array[0], *counts, *sorted = malloc(sizeof(int) * size);

	if (size < 2 || array == NULL)
		return;

	for (i = 1; (unsigned long int) i < size; i++)
		if (array[i] > max)
			max = array[i];

	counts = malloc(sizeof(int) * max + 1);

	for (i = 0; i <= max; i++)
		counts[i] = 0;

	for (i = 0; (unsigned long int) i < size; i++)
		counts[array[i]]++;

	for (i = 1; i <= max; i++)
		counts[i] += counts[i - 1];

	print_array(counts, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		counts[array[i]]--;
		sorted[counts[array[i]]] = array[i];
	}

	for (i = 0; (unsigned long int) i < size; i++)
		array[i] = sorted[i];

	free(counts);
	free(sorted);
}

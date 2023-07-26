#include "sort.h"

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the list to be sorted
 * @size: number of element in @array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

/**
 * sort - sorts an array of integers using Lomuto partition scheme
 * @array: the list to be sorted
 * @size: the size of @array
 */
void sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi);
		print_array(array, size);
		sort(array, lo, p - 1, size);
		sort(array, p + 1, hi, size);
	}
}

/**
 * partition - divide array into two partitions
 * @array: the array to be divided
 * @lo: the lowest index of the @array
 * @hi: the highest index of the @array
 */
int partition(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo, j;
	int temp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}	
	}

	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;

	return (i);
}

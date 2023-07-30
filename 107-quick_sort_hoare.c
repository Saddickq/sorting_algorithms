#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the list to be sorted
 * @size: the size of @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	sort_hoare(array, 0, size - 1, size);
}

/**
 * sort_hoare - algorithm for sorting an array using
 * hoare patition scheme
 * @array: the list
 * @lo: the lowest index
 * @hi: the heighest index
 * @size: the size of the array
 */
void sort_hoare(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		p = h_partition(array, lo, hi, size);
		sort_hoare(array, lo, p - 1, size);
		sort_hoare(array, p, hi, size);
	}
}

/**
 * h_partition - divide an array into two
 * @array: the array
 * @lo: the lowest index of the array
 * @hi: the hightest index of the array
 * @size: the size of the array
 * Return: the pivot
 */
int h_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int temp;

	lo--, hi++;

	while (1)
	{
		lo++, hi--;

		while (array[lo] < pivot)
			lo++;

		while (array[hi] > pivot)
			hi--;

		if (lo >= hi)
			return (lo);

		temp = array[lo];
		array[lo] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
}

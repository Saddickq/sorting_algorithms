#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: the dubbly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *hi = NULL, *lo = NULL, *temp = *list;
	int no_swaps;

	if (*list == NULL || (*list)->next == NULL)
		return;
	do {
		no_swaps = 1;
		while (temp->next != hi)
		{
			if (temp->n > temp->next->n)
			{
				swap(temp, list, &no_swaps);
				continue;
			}
			temp = temp->next;
		}
		if (no_swaps)
			break;
		hi = temp;
		temp = temp->prev;
		no_swaps = 1;
		while (temp->prev != lo)
		{
			if (temp->n > temp->next->n)
			{
				swap(temp, list, &no_swaps);
				temp = temp->prev;
			}
			temp = temp->prev;
		}
		if (temp->n > temp->next->n)
		{
			swap(temp, list, &no_swaps);
			temp = temp->prev;
		}
		if (no_swaps)
			break;
		lo = temp;
		temp = temp->next;
	} while (hi != lo && hi->prev != lo);
}

/**
 * swap - swap two element in a doubly-linked list
 * @curr: the current item to swap
 * @head: the head of the list
 * @no_swaps: value for checking if a swap was made
 */
void swap(listint_t *curr, listint_t **head, int *no_swaps)
{
	listint_t *temp = curr->next;

	curr->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = curr;
	temp->next = curr;
	temp->prev = curr->prev;
	if (curr->prev != NULL)
		curr->prev->next = temp;
	curr->prev = temp;
	if (temp->prev == NULL)
		*head = temp;

	print_list(*head);
	*no_swaps = 0;
}

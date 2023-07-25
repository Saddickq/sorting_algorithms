#include "sort.h"
/**
 * insertion_sort_list - A function that sorts all the nodes in a
 * doubly linked list using insertion sort algorithm
 *
 * @list: The head node of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;
	temp = *list;
	while (temp != NULL)
	{
		current = temp;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		temp = temp->next;
	}

}

/**
 * swap_nodes - swap the nodes
 * @head: the head of the doubly linked lists
 * @node1: node 1
 * @node2: node 2
 * Return: void
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*head = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->next = node1;

	node2->prev = node1->prev;
	node1->prev = node2;

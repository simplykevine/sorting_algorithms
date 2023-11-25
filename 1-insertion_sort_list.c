/*
 * File_name: 1-insertion_sort_list.c
 * Created: 15-NOVEMBER-2023
 * Author: UMUTONI Kevine(simplykevine)
 * Size: large
 * Project: 0x1B. C - Sorting algorithms & Big O
 * Status: not yet submitted.
 * Partner: UMUTONI Kevine (only)
 */


#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to a pointer to the head of the doubly linked list.
 * @l: The left node to swap.
 * @r: The right node to swap.
 *
 * Description: This function swaps two nodes in a doubly linked list.
 *              It updates the necessary pointers to maintain the integrity
 *              of the list after the swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 * return: void
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

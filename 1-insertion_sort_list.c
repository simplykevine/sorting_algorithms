
/*
 * File_Name: 1-insertion_sort
 * Created: 15-NOV-2023
 * Author: UMUTONI Kevine (simplykevine)
 * Size_Of_File: Undefined
 * Project_Title: sorting_algorithms
 * Status: not yet Submitted.!
 * partner: UMUTONI Kevine (simplykevine)
 */
#include "sort.h"
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *next = NULL;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;
	for (; temp; temp = next)
	{
		next = temp->next;
		while (temp->prev && temp->prev->n > temp->n)
		{
			/* Swap adjacent nodes */
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;

			/* Print the current state of the list */
			print_list(*list);
		}
		temp = next;
	}
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *iter, *insert, *tmp;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        reurn;
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

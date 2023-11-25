/*
 * File_name: 0-bubble_sort.c
 * Created: 15-NOVEMBER-2023
 * Author: UMUTONI Kevine(simplykevine)
 * Size: large
 * Project: 0x1B. C - Sorting algorithms & Big O
 * Status: not yet submitted.
 * Partner: UMUTONI Kevine (only)
 */

#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				/* Swap adjacent elements */
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/* Print the current state of the array */
				print_array(array, size);
			}
		}
	}
}

/*
 * File_name: 2-selection_sort.c
 * Created: 15-NOVEMBER-2023
 * Author: UMUTONI Kevine(simplykevine)
 * Size: large
 * Project: 0x1B. C - Sorting algorithms & Big O
 * Status: not yet submitted.
 * Partner: UMUTONI Kevine (only)
 */


#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * @l: The index of the left item.
 *
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			swap = array[i];
			array[i] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}

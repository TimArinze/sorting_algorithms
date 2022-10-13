#include "sort.h"
/**
 * shell_sort - A function that sorts an array of integers in ascending order
 * using the shell sort algorithm using Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	int interval = 1, inner, outer, valueToInsert;
	int n = size;

	/* calculate interval*/
	while (interval <= n / 3)
		interval = (interval * 3) + 1;
	while (interval > 0)
	{
		for (outer = interval; outer < n; outer++)
		{
			/* select value to be inserted */
			valueToInsert = array[outer];
			inner = outer;

			/* shift element towards right */
			while (inner > interval - 1 && array[inner - interval] >= valueToInsert)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}

			/* insert the number at hole position */
			array[inner] = valueToInsert;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}

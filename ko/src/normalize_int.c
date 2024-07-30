/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:35 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/20 15:55:00 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_parser.h"

// include begin, exclude end
// return index of the array
static int	binary_search(const int *arr, int target, int begin, int end)
{
	int	mid;

	while (end != begin)
	{
		mid = (begin + end) >> 1;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	return (begin);
}

// include both, left and right.
static void	quick_sort(int *arr, int left, int right)
{
	int			i;
	int			j;
	const int	pivot = arr[(left + right) >> 1];
	int			temp;

	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
		}
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

static int	duplicate_check(int *arr, int size)
{
	int	idx;

	idx = -1;
	while (++idx < size - 1)
	{
		if (arr[idx] == arr[idx + 1])
			return (0);
	}
	return (1);
}

int	normailize_int(int *arr, int size)
{
	int	*sorted_arr;
	int	idx;

	sorted_arr = (int *)malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
		return (0);
	idx = -1;
	while (++idx < size)
		sorted_arr[idx] = arr[idx];
	quick_sort(sorted_arr, 0, size - 1);
	if (!duplicate_check(sorted_arr, size))
	{
		free(sorted_arr);
		return (0);
	}
	idx = -1;
	while (++idx < size)
		arr[idx] = binary_search(sorted_arr, arr[idx], 0, size);
	free(sorted_arr);
	return (1);
}

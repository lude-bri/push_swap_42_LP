/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:10:27 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:50:01 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_a(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int start, int end)
{
	unsigned int		partition_size;
	unsigned int		big_pivot;
	// unsigned int		small_pivot;

	partition_size = (end - start) / 3;
	big_pivot = end - partition_size;
	// small_pivot = big_pivot - partition_size;
	if (end - start <= 5)
		sort_base_case(stack_a, stack_b, stack_root, end - start, 0);
	else
	{
		split_a(stack_a, stack_b, stack_root, start, end);	
		if (!is_a_sorted(stack_a, stack_root, partition_size))
			quick_a(stack_a, stack_b, stack_root, big_pivot, end);
				// if (is_b_sorted(stack_b, stack_root, partition_size))
		// 	push_a_n(stack_a, stack_b, stack_root, partition_size);
		//
		// else
		// 	quick_b(stack_a, stack_b, stack_root, small_pivot, big_pivot);
		// if (is_b_sorted(stack_b, stack_root, small_pivot - start))
		// 	push_a_n(stack_a, stack_b, stack_root, small_pivot - start);
		// else
		// 	quick_b(stack_a, stack_b, stack_root, start, small_pivot);
	}
}

void	quick_b(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int start, int end)
{
	int		partition_size;
	 int		small_pivot;
	 int		big_pivot;
	 int		i;

	partition_size = (end - start) / 3;
	small_pivot = start + partition_size;
	big_pivot = small_pivot + partition_size;
	if (end - start <= 5)
		sort_base_case(stack_a, stack_b, stack_root, end - start, 1);
	else
	{
		split_b(stack_a, stack_b, stack_root, start, end);
		if(!is_a_sorted(stack_a, stack_root, end - big_pivot))
			quick_a(stack_a, stack_b, stack_root, big_pivot, end);
		i = -1;
		while (++i < partition_size)
			do_cmd(stack_a, stack_b, stack_root, RRR);
		if (!is_a_sorted(stack_a, stack_root, big_pivot - small_pivot))
			quick_a(stack_a, stack_b, stack_root, small_pivot, big_pivot);
		if(is_b_sorted(stack_a, stack_root, small_pivot - start))
			push_a_n(stack_a, stack_b, stack_root, partition_size);
		else
			quick_b(stack_a, stack_b, stack_root, start, small_pivot);
	}
}

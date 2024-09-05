/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_partitions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:21:23 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 14:13:42 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_first(t_stack **stack_a, t_stack **stack_b, int start, t_stack_root **stack_root)
{
	int		partition_size;
	int		big_pivot;
	int		small_pivot;
	int		end;
	int		i;

	end = (*stack_root)->size_a;
	partition_size = (end - start) / 3;
	big_pivot = end - partition_size;
	small_pivot = big_pivot - partition_size - 1;
	i = -1;
	while (++i < end - start)
	{
		if (a_top(stack_a, stack_root) >= big_pivot)
			do_cmd(stack_a, stack_b, stack_root, RA);
		else if (a_top(stack_a, stack_root) >= start && small_pivot > a_top(stack_a, stack_root))
		{
			do_push_cmd(stack_a, stack_b, stack_root, PB);
			do_cmd(stack_a, stack_b, stack_root, RB);
		}
		else
			do_push_cmd(stack_a, stack_b, stack_root, PB);
	}
}

void	split_a(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int start, int end)
{
	int		partition_size;
	int		big_pivot;
	int		small_pivot;
	int		i;

	partition_size = (end - start) / 3;
	big_pivot = end - partition_size;
	small_pivot = big_pivot - partition_size;
	i = -1;
	while (++i < end - start)
	{
		if (a_top(stack_a, stack_root) >= big_pivot && a_top(stack_a, stack_root) < end)
			do_cmd(stack_a, stack_b, stack_root, RA);
		else if (small_pivot <= a_top(stack_a, stack_root) && a_top(stack_a, stack_root) < big_pivot)
		{
			do_push_cmd(stack_a, stack_b, stack_root, PB);
			do_cmd(stack_a, stack_b, stack_root, RB);
		}
		else
			do_push_cmd(stack_a, stack_b, stack_root, PB);
	}
	i = -1;
	while (++i < partition_size)
		do_cmd(stack_a, stack_b, stack_root, RRR);
}

void	split_b(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int start, int end)
{
	int		partition_size;
	int		small_pivot;
	int		big_pivot;
	int		i;

	partition_size = (end - start) / 3;
	small_pivot = start + partition_size - 1;
	big_pivot = small_pivot + partition_size;
	i = -1;
	while (++i < end - start)
	{
		if (b_top(stack_b, stack_root) >= big_pivot && b_top(stack_b, stack_root) < end)
			do_cmd(stack_a, stack_b, stack_root, RA);
		else if (small_pivot <= b_top(stack_b, stack_root) && b_top(stack_b, stack_root) < big_pivot)
		{
			do_push_cmd(stack_a, stack_b, stack_root, PB);
			do_cmd(stack_a, stack_b, stack_root, RB);
		}
		else
			do_push_cmd(stack_a, stack_b, stack_root, PB);
	}
}

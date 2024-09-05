/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:04 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 13:59:18 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ab(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int		partition_size;
	int		big_pivot;
	int		small_pivot;

	partition_size = (*stack_root)->size_a;
	big_pivot = (*stack_root)->size_a - partition_size;
	small_pivot = big_pivot - partition_size;

	if ((*stack_root)->size_a <= 5)
		sort_base_case(stack_a, stack_b, stack_root, (*stack_root)->size_a);
	else
	{
		split_first(stack_a, stack_b, 0, stack_root);
		if (!is_a_sorted(stack_a, stack_root, partition_size))
			quick_a(stack_a, stack_b, stack_root, big_pivot, (*stack_root)->size_a);
		if (is_b_sorted(stack_b, stack_root, partition_size))
			push_a_n(stack_a, stack_b, stack_root, partition_size);
		else
			quick_b(stack_a, stack_b, stack_root, small_pivot, big_pivot);
		if (is_b_sorted(stack_b, stack_root, small_pivot))
			push_a_n(stack_a, stack_b, stack_root, small_pivot);
		else
			quick_b(stack_a, stack_b, stack_root, 0, small_pivot);
	}
}

void	sort_base_case(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int size)
{
	if (size == 2)
		do_cmd(stack_a, stack_b, stack_root, SA);
	else if (size == 3)
		sort_3(stack_a, stack_root);
	else if (size == 4)
		sort_4(stack_a, stack_b, stack_root);
	else if (size == 5)
		sort_5(stack_a, stack_b, stack_root);
}


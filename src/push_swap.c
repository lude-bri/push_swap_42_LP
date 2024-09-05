/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:04 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 14:14:43 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b, t_stack_root *stack_root)
{
	t_stack		*current;
	int			i;

	i = -1;
	current = stack_a;
	(void)(*stack_b);
	if (stack_root->size_b != 0)
		return (0);
	while (++i < stack_root->size_a - 1)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_ab(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	(void)(*stack_b);
	if ((*stack_root)->size_a <= 5)
		sort_base_case(stack_a, stack_b, stack_root);
	else
	{
		split_first(stack_a, stack_b, 0, stack_root);
	}
}

void	sort_base_case(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int		size;

	size = (*stack_root)->size_a;

	if (size == 2)
		do_cmd(stack_a, stack_root, SA);
	else if (size == 3)
		sort_3(stack_a, stack_root);
	else if (size == 4)
		sort_4(stack_a, stack_b, stack_root);
	else if (size == 5)
		sort_5(stack_a, stack_b, stack_root);
}

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
	small_pivot = big_pivot - partition_size;
	i = -1;
	while (++i < end - start)
	{
		if (big_pivot <= a_top(stack_a, stack_root) && a_top(stack_a, stack_root) < end)
			do_cmd(stack_a, stack_root, RA);
		else if (start <= a_top(stack_a, stack_root) && a_top(stack_a, stack_root) < small_pivot)
		{
			do_push_cmd(stack_a, stack_b, stack_root, PB);
			do_cmd(stack_a, stack_root, RB);
		}
		else
			do_push_cmd(stack_a, stack_b, stack_root, PB);
	}
}

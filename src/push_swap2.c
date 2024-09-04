/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:50:37 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 15:04:23 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack, t_stack_root **stack_root)
{
	t_stack *big;

	big = find_big(*stack, (*stack_root)->size_a);
	if (!is_sorted(*stack, (void *)(stack), *stack_root))
	{
		if (*stack == big)
			do_cmd(stack, RA);
		else if ((*stack)->next == big)
			do_cmd(stack, RRA);
		if ((*stack)->num > (*stack)->next->num)
			do_cmd(stack, SA);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int		size;

	size = (*stack_root)->size_a;
	
	while (size > 0)
	{
		if (!is_sorted(*stack_a, *stack_b, *stack_root))
		{	
			if ((*stack_a)->num == 0)
			{
				do_push_cmd(stack_a, stack_b, PB);
				break ;
			}
			else
				do_cmd(stack_a, RA);
		}
		size--;
	}
	sort_3(stack_a, stack_root);
	do_push_cmd(stack_a, stack_b, PA);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int		size;

	size = (*stack_root)->size_a;
	while (size > 0)
	{
		if (!is_sorted(*stack_a, *stack_b, *stack_root))	
		{
			if ((*stack_a)->num == 0)
				do_push_cmd(stack_a, stack_b, PB);
			else if ((*stack_a)->num == 1)
				do_push_cmd(stack_a, stack_b, PB);
			else
				do_cmd(stack_a, RA);
		}
		if ((*stack_b)->num == 0 && (*stack_b)->next->num == 1)
			break ;
		size--;
	}
	sort_3(stack_a, stack_root);
	if ((*stack_b)->num < (*stack_b)->next->num)
		do_cmd(stack_b, RB);
	do_push_cmd(stack_a, stack_b, PA);
	do_push_cmd(stack_a, stack_b, PA);
}

t_stack	*find_big(t_stack *stack, int size)
{
	int			n;
	t_stack		*high_node;

	n = 0;
	while (size)
	{
		if (stack->num > n)
		{
			n = stack->num;
			high_node = stack;
		}
		stack = stack->next;
		size--;
	}
	return (high_node);
}


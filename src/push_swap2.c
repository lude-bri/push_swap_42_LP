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

void	sort_3(t_stack **stack)
{
	t_stack *big;

	big = find_big(*stack);
	if (*stack == big)
		do_cmd(stack, RA);
	else if ((*stack)->next == big)
		do_cmd(stack, RRA);
	if ((*stack)->num > (*stack)->next->num)
		do_cmd(stack, SA);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = (*stack_a)->size;
	
	while (size > 0)
	{
		if ((*stack_a)->num == 0)
		{
			do_push_cmd(stack_a, stack_b, PB);
			break ;
		}
		else
			do_cmd(stack_a, RA);
		size--;
	}
	sort_3(stack_a);
	do_push_cmd(stack_a, stack_b, PA);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = (*stack_a)->size;
	
	while (size > 0)
	{
		if ((*stack_a)->num == 0)
		{
			do_push_cmd(stack_a, stack_b, PB);
			break ;
		}
		else
			do_cmd(stack_a, RA);
		size--;
	}
	sort_4(stack_a, stack_b);
	do_push_cmd(stack_a, stack_b, PA);
}

t_stack	*find_big(t_stack *stack)
{
	int			n;
	int			size;
	t_stack		*high_node;

	n = 0;
	size = stack->size;
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

t_stack *find_num(t_stack *stack, int num)
{
	int			size;
	t_stack		*small_node;

	size = stack->size;
	small_node = stack;
	while (size)
	{
		if (small_node->num == num)
			return (small_node);
		small_node = small_node->next;
		size--;
	}
	return (NULL);
}

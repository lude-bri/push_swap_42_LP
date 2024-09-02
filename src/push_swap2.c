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

void	sort_4(t_stack **stack)
{
	t_stack *small;
	t_stack *stack_b;
	int		i;

	i = 0;
	small = find_small(*stack);
	while (i != (*stack)->num && (*stack)->size == 4)
	{
		if (i == small->num)
			do_push_cmd(stack, &stack_b, PB);
		else
			do_cmd(stack, RA);
	}
	sort_3(stack);
	do_push_cmd(stack, &stack_b, PA);
	free(stack_b);
}

void	sort_5(t_stack **stack)
{
	if (*stack != 0)
		return ;
	return ;
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

t_stack *find_small(t_stack *stack)
{
	int			n;
	int			size;
	t_stack		*small_node;

	n = 0;
	size = stack->size;
	small_node = stack;
	while (size)
	{
		if (small_node->num == n)
			return (small_node);
		small_node = small_node->next;
		size--;
	}
	return (NULL);
}

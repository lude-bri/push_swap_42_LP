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

	stack_b = NULL;
	small = find_num(*stack, 0);
	while ((*stack)->num != 0 && (*stack)->size == 4)
	{
		if (small->num == 0)
			do_push_cmd(stack, &stack_b, PB);
		else
			do_cmd(stack, RA);
	}
	sort_3(stack);
	do_push_cmd(stack, &stack_b, PA);
	free_stack(stack_b);
}

void	sort_5(t_stack **stack)
{
	t_stack		*small;
	t_stack		*stack_b;

	stack_b = NULL;
	small = find_num(*stack, 0);
	while ((*stack)->num != 0 && (*stack)->size == 5)
	{
		if (small->num == 0)
			do_push_cmd(stack, &stack_b, PB);
		else
			do_cmd(stack, RA);
	}
	sort_4(stack);
	do_push_cmd(stack, &stack_b, PA);
	free_stack(stack_b);
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

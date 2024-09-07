/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:50:37 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 13:52:58 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack, t_stack_root **stack_root)
{
	t_stack *big;

	if  (!*stack)
		return ;
	big = find_big(*stack, (*stack_root)->size_a);
	if (!is_sorted(*stack, (void *)(stack), *stack_root))
	{
		if (*stack == big)
			do_cmd(stack, (void *)(stack), stack_root, RA);
		else if ((*stack)->next == big)
			do_cmd(stack, (void *)(stack), stack_root, RRA);
		if ((*stack)->num > (*stack)->next->num)
			do_cmd(stack, (void *)(stack), stack_root, SA);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int			size;
	t_stack		*stack;

	stack = find_small(stack_a, (*stack_root)->size_a);
	if (!*stack_a || !*stack_b)
		return ;
	size = (*stack_root)->size_a;
	while (size > 0)
	{
		if (!is_sorted(*stack_a, *stack_b, *stack_root))
		{	
			if ((*stack_a)->num == stack->num)
			{
				do_push_cmd(stack_a, stack_b, stack_root, PB);
				break ;
			}
			else
				do_cmd(stack_a, stack_b, stack_root, RA);
		}
		size--;
	}
	sort_3(stack_a, stack_root);
	do_push_cmd(stack_a, stack_b, stack_root, PA);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int			size;
	t_stack		*small;

	if (!*stack_a || !*stack_b)
		return ;
	size = (*stack_root)->size_a;
	small = find_small(stack_a, (*stack_root)->size_a);
	while (size > 0)
	{
		if (!is_sorted(*stack_a, *stack_b, *stack_root))	
		{
			if ((*stack_a)->num == small->num)
				do_push_cmd(stack_a, stack_b, stack_root, PB);
			else if ((*stack_a)->num == small->num + 1)
				do_push_cmd(stack_a, stack_b, stack_root, PB);
			else
				do_cmd(stack_a, stack_b, stack_root, RA);
		}
		if ((*stack_b)->num == small->num && (*stack_b)->next->num == small->num + 1)
			break ;
		size--;
	}
	sort_3(stack_a, stack_root);
	if ((*stack_b)->num < (*stack_b)->next->num)
		do_cmd(stack_a, stack_b, stack_root, RB);
	do_push_cmd(stack_a, stack_b, stack_root, PA);
	do_push_cmd(stack_a, stack_b, stack_root, PA);
}

t_stack	*find_big(t_stack *stack, int size)
{
	int			n;
	t_stack		*high_node;
	
	if (!stack)
		return (NULL);
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

t_stack	*find_small(t_stack **stack, int size)
{
	int			n;
	t_stack		*small_node;

	if (!stack)
		return (NULL);
	n = 0;
	while (size)
	{
		if ((*stack)->num <= 0)
		{
			n = (*stack)->num;
			small_node = (*stack);
		}
		(*stack) = (*stack)->next;
		size--;
	}
	return (small_node);
}

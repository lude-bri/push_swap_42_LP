/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:53:35 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:02:25 by luigi            ###   ########.fr       */
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

int	is_a_sorted(t_stack **stack, t_stack_root **stack_root, int size)
{
	t_stack		*current;
	int			value;
	int			i;

	current = (*stack);
	if (size > (*stack_root)->size_a)
		return (0);
	if (size <= 1)
		return (1);
	i = 0;
	value = a_top(stack, stack_root);
	while (++i < size)
	{
		if (current->num != value)
			return (0);
		current = current->next;
		++value;
	}
	return (1);
}

int	is_b_sorted(t_stack **stack, t_stack_root **stack_root, int size)
{
	t_stack		*current;
	int			value;
	int			i;

	current = (*stack);
	if (size > (*stack_root)->size_b)
		return (0);
	if (size <= 1)
		return (1);
	i = 0;
	value = b_top(stack, stack_root);
	while (++i < size)
	{
		if (current->num != value)
			return (0);
		current = current->next;
		++value;
	}
	return (1);
}

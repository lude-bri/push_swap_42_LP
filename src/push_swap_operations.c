/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:42:29 by luigi             #+#    #+#             */
/*   Updated: 2024/08/08 11:56:29 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_push(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (!*stack)
	{
		new->next = new;
		new->prev = new;
		*stack = new;
		return ;
	}
	new->next = *stack;
	new->prev = (*stack)->prev;
	(*stack)->prev->next = new;
	(*stack)->prev = new;
	*stack = new;
}

t_stack	*num_pop(t_stack **stack)
{
	t_stack	*num;

	if (!stack)
		return (NULL);
	num = *stack;
	if (num->next == num)
		*stack = NULL;
	else
	{
		num->prev->next = num->next;
		num->next->prev = num->prev;
		*stack = num->next;
	}
	num->next = NULL;
	num->prev = NULL;
	return (num);
}

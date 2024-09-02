/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:09:33 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 12:29:50 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rra (reverse rotate a) - Shift down all elements of stack a by 1. The last element becomes the first one.
void rra(t_stack **stack)
{
    t_stack		*last_node;
    t_stack		*new_last_node;

    last_node = (*stack)->prev;
	new_last_node = last_node->prev;

	(*stack)->prev = new_last_node;
	last_node->next = *stack;
	last_node->prev = new_last_node;
	*stack = last_node;
	new_last_node->next = *stack;
}

//rrb (reverse rotate b) - Shift down all elements of stack b by 1. The last element becomes the first one.
void	rrb(t_stack **stack)
{
	t_stack		*last_node;
    t_stack		*new_last_node;

    last_node = (*stack)->prev;
	new_last_node = last_node->prev;

	(*stack)->prev = new_last_node;
	last_node->next = *stack;
	last_node->prev = new_last_node;
    *stack = last_node;
	new_last_node->next = *stack;
}

//rrr (reverse rotate a and reverse rotate b) - Do rra and rrb
void	rrr(t_stack **stack)
{
	rra(stack);
	rrb(stack);
}


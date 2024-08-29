/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:08:52 by luigi             #+#    #+#             */
/*   Updated: 2024/08/29 10:57:07 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra (rotate a) - Shift up all elements of stack a by 1. The first elements becomes the last one.
void	ra(t_stack **stack)
{
	t_stack	*last_node;
	t_stack *current;

	current = *stack;
	last_node = find_lastnode(*stack);
	*stack = (*stack)->next;
	last_node->next = current;
	last_node->next->next = *stack;
}

//rb (rotate b) - Shift up all elements of stack b by 1. The first element becomes the last one.
void	rb(t_stack **stack)
{
	t_stack	*last_node;
	t_stack *current;

	current = *stack;
	last_node = find_lastnode(*stack);
	*stack = (*stack)->next;
	last_node->next = current;
	last_node->next->next = *stack;
}

//rr (rotate a and rotate b) - Do ra and rb
void	rr(t_stack **stack)
{
	ra(stack);
	rb(stack);
}



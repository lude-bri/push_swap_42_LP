/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:07:26 by luigi             #+#    #+#             */
/*   Updated: 2024/08/29 11:04:00 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa (push a) - Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	pa(t_stack **stack_a, t_stack **stack_b)
{	
	t_stack *curr;
	t_stack *head_b;

	if (!(*stack_a))
	{
		(*stack_a) = *stack_b;
		(*stack_b)->prev->next = (*stack_b)->next;
		(*stack_b)->next->prev = (*stack_b)->prev;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
	else
	{
		curr = (*stack_a);
		head_b = (*stack_b)->next;
		(*stack_a) = (*stack_b);
		(*stack_b)->prev->next = (*stack_b)->next;
		(*stack_b)->next->prev = (*stack_b)->prev;
		(*stack_b) = head_b; // stack_b feito
		
		(*stack_a)->next = curr;
		(*stack_a)->prev = curr->prev;
		curr->prev = (*stack_a);
		curr->prev->next = (*stack_a);
		(*stack_a) = curr;
	}
}

//pb (push b) - Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *curr;
	t_stack *head_a;

	if (!(*stack_b))
	{
		(*stack_b) = *stack_a;
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
	}
	else
	{
		curr = (*stack_b);
		head_a = (*stack_a)->next;
		(*stack_b) = (*stack_a);
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		(*stack_a) = head_a; // stack_a feito
		
		(*stack_b)->next = curr;
		(*stack_b)->prev = curr->prev;
		curr->prev = (*stack_b);
		curr->prev->next = (*stack_b);
		(*stack_b) = curr;
	}
}


	// t_stack		*current;
	//
	// if (a_size(*stack_a) != 0)
	// {
	// 	current = *stack_a;
	// 	*stack_a = (*stack_a)->next;
	// 	current->next = *stack_b;
	// 	*stack_b = current;
	// }



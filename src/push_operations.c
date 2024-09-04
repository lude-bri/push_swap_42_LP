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
	t_stack		*current;

	if (!(*stack_b))
		return ;
	current = *stack_b;
	//if there is only one element, now its empty
	if ((*stack_b)->next == *stack_b)
		*stack_b = NULL;
	else
	{
		(*stack_b)->prev->next = (*stack_b)->next;
		(*stack_b)->next->prev = (*stack_b)->prev;
		*stack_b = (*stack_b)->next; //new head
	}
	current->prev = (*stack_a)->prev;
	current->next = *stack_a;
	(*stack_a)->prev->next = current;
	(*stack_a)->prev = current;
	*stack_a = current;
	update_stack_size(stack_a, stack_b, PA);
}

//pb (push b) - Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;

	if (!(*stack_a))
		return ;
	current = *stack_a;
	if ((*stack_a)->next == *stack_a)
		*stack_a = NULL;
	else
	{
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		*stack_a = (*stack_a)->next; //new head
	}
	if (!(*stack_b))
		if_empty(stack_b);
	else
	{
		current->prev = (*stack_b)->prev;
		current->next = *stack_b;
		(*stack_b)->prev->next = current;
		(*stack_b)->prev = current;
		*stack_b = current; //new element of stack_b
	}
	update_stack_size(stack_a, stack_b, PB);
}

void	update_stack_size(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag == PA)
	{
		while ((*stack_a)->prev != (*stack_a))
		{
			(*stack_a)->size += 1;
			(*stack_b)->size -= 1;
			(*stack_a) = (*stack_a)->next;
			(*stack_b) = (*stack_b)->next;
		}

	}
	else if (flag == PB)
	{
		while ((*stack_a)->prev != (*stack_a))
		{
			(*stack_a)->size += 1;
			(*stack_b)->size -= 1;
			(*stack_a) = (*stack_a)->next;
			(*stack_b) = (*stack_b)->next;
		}
	}
}

void	if_empty(t_stack **stack)
{
	t_stack	*current;

	current = *stack;

	current->next = current;
	current->prev = current;
	*stack = current;
}

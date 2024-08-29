/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:07:26 by luigi             #+#    #+#             */
/*   Updated: 2024/08/29 10:08:02 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa (push a) - Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*current;

	if (b_size(stack_b) != 0)
	{
		current = stack_b;
		stack_b = stack_b->next;
		current->next = stack_a;
		stack_a = current;
	}
}

//pb (push b) - Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*current;

	if (a_size(stack_a) != 0)
	{
		current = stack_a;
		stack_a = stack_b->next;
		current->next = stack_b;
		stack_b = current;
	}
}


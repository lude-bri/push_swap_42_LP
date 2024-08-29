/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:05:49 by luigi             #+#    #+#             */
/*   Updated: 2024/08/29 11:01:54 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa (swap a) - Swap the 2 first elements at the top of stack a. Do nothing if there is only one or no elements.
void	sa(t_stack **stack)
{
	int		tmp;

	if ((*stack)->size > 1)
	{
		tmp = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = tmp;
	}
}

//sb (swap b) - Swap the 2 first elements at the top of stack b. Do nothing if there is only one or no elements.
void	sb(t_stack **stack)
{
	int		tmp;

	if ((*stack)->size > 1)
	{
		tmp = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = tmp;
	}
}

//ss (swap a and swap b) - do sa and sb at the same time
void	ss(t_stack **stack)
{
	sa(stack);
	sb(stack);
}

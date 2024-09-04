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
void	sa(t_stack **stack, t_stack_root **stack_root)
{
	int		tmp;

	if ((*stack_root)->size_a > 1)
	{
		tmp = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = tmp;
	}
	ft_printf("sa\n");
}

//sb (swap b) - Swap the 2 first elements at the top of stack b. Do nothing if there is only one or no elements.
void	sb(t_stack **stack, t_stack_root **stack_root)
{
	int		tmp;

	if ((*stack_root)->size_b > 1)
	{
		tmp = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = tmp;
	}
	ft_printf("sb\n");
}

//ss (swap a and swap b) - do sa and sb at the same time
void	ss(t_stack **stack, t_stack_root **stack_root)
{
	sa(stack, stack_root);
	sb(stack, stack_root);
	ft_printf("ss\n");
}

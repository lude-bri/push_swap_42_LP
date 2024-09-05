/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:09:33 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:45:48 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rra (reverse rotate a) - Shift down all elements of stack a by 1. The last element becomes the first one.
void rra(t_stack **stack)
{
	*stack = (*stack)->prev;
	ft_printf("rra\n");
}

//rrb (reverse rotate b) - Shift down all elements of stack b by 1. The last element becomes the first one.
void	rrb(t_stack **stack)
{
	*stack = (*stack)->prev;
	ft_printf("rrb\n");
}

//rrr (reverse rotate a and reverse rotate b) - Do rra and rrb
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}


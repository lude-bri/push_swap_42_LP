/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:08:52 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:46:55 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra (rotate a) - Shift up all elements of stack a by 1. The first elements becomes the last one.
void	ra(t_stack **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	ft_printf("ra\n");
}

//rb (rotate b) - Shift up all elements of stack b by 1. The first element becomes the last one.
void	rb(t_stack **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	ft_printf("rb\n");
}

//rr (rotate a and rotate b) - Do ra and rb
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}



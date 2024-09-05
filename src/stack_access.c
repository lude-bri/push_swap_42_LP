/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:43:13 by luigi             #+#    #+#             */
/*   Updated: 2024/08/29 08:48:46 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_top(t_stack **stack, t_stack_root **stack_root)
{
	if ((*stack_root)->size_a > 0)
		return ((*stack)->num);
	return (-1);
}

int	b_top(t_stack **stack, t_stack_root **stack_root)
{
	if ((*stack_root)->size_b > 0)
		return ((*stack)->num);
	return (-1);
}

int	a_bottom(t_stack **stack, t_stack_root **stack_root)
{
	if ((*stack_root)->size_a > 0)
		return ((*stack)->a_bottom);
	return (-1);
}

int	b_bottom(t_stack **stack, t_stack_root  **stack_root)
{
	if ((*stack_root)->size_b > 0)
		return ((*stack)->b_bottom);
	return (-1);
}

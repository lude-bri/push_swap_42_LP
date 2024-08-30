/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:04 by luigi             #+#    #+#             */
/*   Updated: 2024/08/29 11:20:03 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*current;
	int			i;

	i = -1;
	current = stack_a;
	if (b_size(stack_b) != 0)
		return (0);
	while (++i < current->size - 1)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

// int	sort_ab(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (stack_a && stack_b)
// 		return (1);
// 	return (0);
// }
//

void	sort_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b)
		return ;
	return ;
}

void	sort_base_case(t_stack *stack, int size, int ab)
{
	if (!stack || size || ab)
		return ;
	return ;
}

int	a_size(t_stack *stack)
{
	return (stack->pivot - stack->a_bottom);
}

int	b_size(t_stack *stack)
{
	return (stack->b_bottom - stack->pivot + 1);
}

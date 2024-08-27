/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:04 by luigi             #+#    #+#             */
/*   Updated: 2024/08/23 14:03:24 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack		*current;
	int			i;

	i = 0;
	current = stack;
	if (b_size(current))
		return (0);
	while (i++ < current->size)
	{
		if (current->num != current->size - 1 - i)
			return (0);
	}
	return (1);
}

void	sort_ab(t_stack *stack)
{
	int		partition_size = stack->size / 3;
	int		big_pivot = stack->size - partition_size;
	int		small_pivot = big_pivot - partition_size;


}

int	a_size(t_stack *stack)
{
	return (stack->pivot - stack->a_bottom);
}

int	b_size(t_stack *stack)
{
	return (stack->b_bottom - stack->pivot + 1);
}

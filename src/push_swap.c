/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:04 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 14:14:43 by luigi            ###   ########.fr       */
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

void	sort_ab(t_stack **stack_a, t_stack **stack_b)
{
	//int	partition_size;
	// int	big_pivot;
	// int	small_pivot;

	// partition_size = (*stack_a)->size / 3;
	// big_pivot = (*stack_a)->size - partition_size;
	// small_pivot = big_pivot - partition_size;
	//
	(void)(*stack_b);
	if ((*stack_a)->size <= 5)
		sort_base_case(stack_a, (*stack_a)->size);

}

void	sort_base_case(t_stack **stack, int size)
{
	if (size == 2)
		do_cmd(stack, SA);
	else if (size == 3)
		sort_3(stack);
	else if (size == 4)
		sort_4(stack);
	else if (size == 5)
		sort_5(stack);
}

int	a_size(t_stack *stack)
{
	return (stack->pivot - stack->a_bottom);
}

int	b_size(t_stack *stack)
{
	return (stack->b_bottom - stack->pivot + 1);
}

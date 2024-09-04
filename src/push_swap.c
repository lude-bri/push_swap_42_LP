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

int	is_sorted(t_stack *stack_a, t_stack *stack_b, t_stack_root *stack_root)
{
	t_stack		*current;
	int			i;

	i = -1;
	current = stack_a;
	(void)(*stack_b);
	if (stack_root->size_b != 0)
		return (0);
	while (++i < current->size - 1)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_ab(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	(void)(*stack_b);
	if ((*stack_root)->size_a <= 5)
		sort_base_case(stack_a, stack_b, stack_root);
}

void	sort_base_case(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{
	int		size;

	size = (*stack_root)->size_a;

	if (size == 2)
		do_cmd(stack_a, SA);
	else if (size == 3)
		sort_3(stack_a, stack_root);
	else if (size == 4)
		sort_4(stack_a, stack_b, stack_root);
	else if (size == 5)
		sort_5(stack_a, stack_b, stack_root);
}


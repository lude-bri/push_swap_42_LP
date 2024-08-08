/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:24:31 by luigi             #+#    #+#             */
/*   Updated: 2024/08/08 12:00:36 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const void	init_stack(t_stack *stack, int size)
{
	stack->a_bottom = 0;
	stack->b_bottom = size - 1;
	stack->pivot = size;
	stack->size = size;
	stack->next = NULL;
	stack->prev = NULL;
}

t_stack *create_stack(char **str)
{
	t_stack		*stack;
	const int	count;
	int			i;

	count = number_sanity_check(str);
	if (count == 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = malloc(sizeof(int) * count);
	if (!stack->num)
		return (free(stack->num), NULL);
	i = count;
	while (i >= 0)
	{
		stack->num = ft_atoi(str[count - i - 1)]);
		stack->next;
		i--;
	}
	init_stack(stack, count);
	if (!to_rank(stack->num, stack->size))
		return (free_stack(stack), NULL);
	return (stack);
}


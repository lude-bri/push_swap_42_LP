/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:07:08 by luigi             #+#    #+#             */
/*   Updated: 2024/09/10 20:30:10 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*take_item(t_stack *stack, int i)
{
	int		head_position;
	int		tail_position;

	if (i >= 0 && i < stack->count)
	{
		head_position = (stack->head + i) % stack->size;
		return (&stack->values[head_position]);
	}
	else if (i < 0 && i >= -stack->count)
	{
		tail_position = (stack->tail + i + stack->size + 1) % stack->size;
		return (&stack->values[tail_position]);
	}
	return (NULL);
}

void	push(t_stack *stack, int value, int position)
{
	stack->count = stack->count + 1;
	if (position == HEAD)
	{
		stack->head = (stack->head + stack->size - 1) % stack->size;
		stack->values[stack->head] = value;
	}
	else if (position == TAIL)
	{
		stack->tail = (stack->tail + 1) % stack->size;
		stack->values[stack->tail] = value;
	}
}

int		pop(t_stack *stack, int position)
{
	int		*item;

	item = take_item(stack, position);
	if (!item)
		return (-1);
	stack->count = stack->count - 1;
	if (position == HEAD)
		stack->head = (stack->head + 1) % stack->size;
	else if (position == TAIL)
		stack->tail = (stack->tail + stack->size - 1) % stack->size;
	return (*item);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:49:44 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 14:58:51 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*peek(t_stack *id, int i)
{
	if (i >= 0 && i < id->count)
		return (&id->values[(id->head + i) % id->size]);
	else if (i < 0 && i >= -id->count)
		return(&id->values[(id->tail + i + id->size + 1) % id->size]);
	return (NULL);
}

void	push(t_stack *stack, int value, int where)
{
	stack->count++;
	if (where == HEAD)
	{
		stack->head = (stack->head + stack->size - 1) % stack->size;
		stack->values[stack->head] = value;
	}
	else if (where == TAIL)
	{
		stack->tail = (stack->tail + 1) % stack->size;
		stack->values[stack->tail] = value;
	}
}

int		pop(t_stack *stack, int where)
{
	int		*item;

	item = peek(stack, where);
	if (!item)
		return (-1);
	stack->count--;
	if (where == HEAD)
		stack->head = (stack->head + 1) % stack->size;
	else if (where == TAIL)
		stack->tail = (stack->tail + stack->size - 1) % stack->size;
	return (*item);
}

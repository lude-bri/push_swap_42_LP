/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:07:08 by luigi             #+#    #+#             */
/*   Updated: 2024/09/12 15:30:30 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*take_item(t_stack *stack, int i)
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
	stack->count++;
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

int	pop(t_stack *stack, int position)
{
	int		*item;

	item = take_item(stack, position);
	if (!item)
		return (-1);
	stack->count--;
	if (position == HEAD)
		stack->head = (stack->head + 1) % stack->size;
	else if (position == TAIL)
		stack->tail = (stack->tail + stack->size - 1) % stack->size;
	return (*item);
}

void	swap(t_stack *stack)
{
	int		tmp;

	if (stack->count < 2)
		return ;
	tmp = *take_item(stack, 0);
	*(take_item(stack, 0)) = *take_item(stack, 1);
	*take_item(stack, 1) = tmp;
}

void	cmd_to_buffer(t_ps *root, char cmd)
{
	static size_t	size;
	static size_t	i;
	char			*tmp;

	if (i == size)
	{
		if (!size)
			size = 1;
		else if (size < 1024)
			size = size * 2;
		else
			size = size + 1024;
		tmp = ft_calloc(size + 1, sizeof(char));
		if (!tmp)
			return ;
		if (root->cmds)
			ft_strlcpy(tmp, root->cmds, size + 1);
		free(root->cmds);
		root->cmds = tmp;
	}
	root->cmds[i++] = cmd;
}

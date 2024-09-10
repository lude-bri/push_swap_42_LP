/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:11:22 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 15:26:04 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int		tmp;

	if (stack->count < 2)
		return ;
	tmp = *peek(stack, 0);
	*(peek(stack, 0)) = *peek(stack, 1);
	*peek(stack, 1) = tmp;
}

static void	queue_cmd(t_ps *data, char cmd)
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
			ft_exit(data, true);
		if (data->cmds)
			ft_strlcpy(tmp, data->cmds, size + 1);
		free(data->cmds);
		data->cmds = tmp;
	}
	data->cmds[i++] = cmd;
}

void	do_cmd(t_ps *data, char cmd)
{
	if (!!(cmd & SWAP) + !!(cmd & PUSH) + !!(cmd & ROT) + !!(cmd & REV) > 1
			|| ((cmd & (PUSH | A | B)) == (PUSH | A | B)))
			return ;
	if (cmd & SWAP && cmd & A)
		swap(data->a);
	if (cmd & SWAP && cmd & B)
		swap(data->b);
	if (cmd & PUSH && cmd & A && data->b->count > 0)
		push(data->a, pop(data->b, HEAD), HEAD);
	if (cmd & PUSH && cmd & B && data->a->count > 0)
		push(data->b, pop(data->a, HEAD), HEAD);
	if (cmd & ROT && cmd & A && data->a->count > 1)
		push(data->a, pop(data->a, HEAD), TAIL);
	if (cmd & ROT && cmd & B && data->b->count > 1)
		push(data->b, pop(data->b, HEAD), TAIL);
	if (cmd & REV && cmd & A && data->a->count > 1)
		push(data->a, pop(data->a, TAIL), HEAD);
	if (cmd & REV && cmd & B && data->b->count > 1)
		push(data->b, pop(data->b, TAIL), HEAD);
	queue_cmd(data, cmd);
}

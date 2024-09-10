/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:28:44 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 15:33:22 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (peek(stack, ++i))
		if (*peek(stack, i - 1) + (stack->id = A) * 2 - 1 != *peek(stack, i))
			return (false);
	return(true);
}

void	bring_to_top(t_ps *data, char id, int n)
{
	t_stack		*stack;
	int			i;

	stack = data->a;
	if (id == B)
		stack = data->b;
	if (n < 0 || stack->count < 2)
		return ;
	i = -1;
	while (++i < stack->count)
		if (*peek(stack, i) == n)
			break ;
	if (i > stack->count / 2)
		while (i++ < stack->count)
			do_cmd(data, REV | stack->id);
	else
		while (i-- > 0)
			do_cmd(data, ROT | stack->id);
}

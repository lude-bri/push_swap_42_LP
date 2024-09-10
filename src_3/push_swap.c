/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:51:03 by luigi             #+#    #+#             */
/*   Updated: 2024/09/10 21:20:55 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cmd(t_ps *stack, char cmd)
{
	if (cmd == SA)
		swap(stack->a);
	if (cmd == SB)
		swap(stack->b);
	if (cmd == PA && stack->b->count > 0)
		push(stack->a, pop(stack->b, HEAD), HEAD);
	if (cmd == PB && stack->a->count > 0)
		push(stack->b, pop(stack->a, HEAD), HEAD);
	if (cmd == RA && stack->a->count > 1)
		push(stack->a, pop(stack->a, HEAD), TAIL);
	if (cmd == RB && stack->b->count > 1)
		push(stack->b, pop(stack->b, HEAD), TAIL);
	if (cmd == RRA && stack->a->count > 1)
		push(stack->a, pop(stack->a, TAIL), HEAD);
	if (cmd == RRB && stack->b->count > 1)
		push(stack->b, pop(stack->b, TAIL), HEAD);
	cmd_to_buffer(stack, cmd);
}



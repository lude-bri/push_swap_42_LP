/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 224/09/02 12:41:10 by luigi             #+#    #+#             */
/*   Updated: 224/09/02 14:25:04 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push_cmd(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int cmd)
{
	if (cmd == PA)
		pa(stack_a, stack_b, stack_root);
	else if (cmd == PB)
		pb(stack_a, stack_b, stack_root);
}

void	do_cmd(t_stack **stack, t_stack_root **stack_root, int cmd)
{
	if (cmd == RA)
		ra(stack);
	else if (cmd == RB)
		rb(stack);
	else if (cmd == RR)
		rr(stack);
	else if (cmd == RRA)
		rra(stack);
	else if (cmd == RRB)
		rrb(stack);
	else if (cmd == RRR)
		rrr(stack);
	else if (cmd == SA)
		sa(stack, stack_root);
	else if (cmd == SB)
		sb(stack, stack_root);
	else if (cmd == SS)
		ss(stack, stack_root);
}

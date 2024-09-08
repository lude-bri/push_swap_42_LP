/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 224/09/02 12:41:10 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:44:42 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cmd(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int cmd)
{
	if (cmd == PA)
		pa(stack_a, stack_b, stack_root);
	else if (cmd == PB)
		pb(stack_a, stack_b, stack_root);
	if (cmd == RA)
		ra(stack_a);
	else if (cmd == RB)
		rb(stack_b);
	else if (cmd == RR)
		rr(stack_a, stack_b);
	else if (cmd == RRA)
		rra(stack_a);
	else if (cmd == RRB)
		rrb(stack_b);
	else if (cmd == RRR)
		rrr(stack_a, stack_b);
	else if (cmd == SA)
		sa(stack_a, stack_root);
	else if (cmd == SB)
		sb(stack_b, stack_root);
	else if (cmd == SS)
		ss(stack_a, stack_b, stack_root);
}

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
	print_cmd(cmd);
}

void	do_cmd(t_stack **stack, int cmd)
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
		sa(stack);
	else if (cmd == SB)
		sb(stack);
	else if (cmd == SS)
		ss(stack);
	print_cmd(cmd);
}

void	print_cmd(int cmd)
{
	if (cmd == PA)
		ft_printf("pa\n");
	else if (cmd == PB)
		ft_printf("pb\n");
	else if (cmd == RA)
		ft_printf("ra\n");
	else if (cmd == RB)
		ft_printf("rb\n");
	else if (cmd == RR)
		ft_printf("rr\n");
	else if (cmd == RRA)
		ft_printf("rra\n");
	else if (cmd == RRB)
		ft_printf("rrb\n");
	else if (cmd == RRR)
		ft_printf("rrr\n");
	else if (cmd == SA)
		ft_printf("sa\n");
	else if (cmd == SB)
		ft_printf("sb\n");
	else if (cmd == SS)
		ft_printf("ss\n");
}

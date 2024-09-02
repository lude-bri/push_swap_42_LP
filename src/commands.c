/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:41:10 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 14:25:04 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	do_push_cmd(t_stack **stack_a, t_stack **stack_b, int cmd)
{
	if (cmd == PA)
		pa(stack_a, stack_b);
	else if (cmd == PB)
		pa(stack_a, stack_b);
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
		ft_putstr_fd("pa\n", 0);
	else if (cmd == PB)
		ft_putstr_fd("pb\n", 0);
	else if (cmd == RA)
		ft_putstr_fd("ra\n", 0);
	else if (cmd == RB)
		ft_putstr_fd("rb\n", 0);
	else if (cmd == RR)
		ft_putstr_fd("rr\n", 0);
	else if (cmd == RRA)
		ft_putstr_fd("rra\n", 0);
	else if (cmd == RRB)
		ft_putstr_fd("rrb\n", 0);
	else if (cmd == RRR)
		ft_putstr_fd("rrr\n", 0);
	else if (cmd == SA)
		ft_putstr_fd("sa\n", 0);
	else if (cmd == SB)
		ft_putstr_fd("sb\n", 0);
	else if (cmd == SS)
		ft_putstr_fd("ss\n", 0);
}

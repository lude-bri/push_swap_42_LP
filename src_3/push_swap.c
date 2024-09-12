/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:51:03 by luigi             #+#    #+#             */
/*   Updated: 2024/09/12 15:57:47 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *root)
{
	int		size;

	size = root->a->count;
	if (is_sorted(root->a))
		return ;
	if (size == 2)
		do_cmd(root, SA);
	else if (size == 3)
		sort_3(root, root->a);
	else if (size <= 5)
		sort_small(root);
	else
		sort_big(root);
	to_top(root, A, 0);
	print_cmds(root->cmds);
}

int is_sorted(t_stack *stack)
{
    int i;
    int *current_item;
    int *next_item;

    i = 0;
    current_item = take_item(stack, i);

    if (!current_item)
        return (1);
    while ((next_item = take_item(stack, ++i)))
    {
		if (*current_item + (stack->id == A ? 1 : -1) != *next_item)
            return (0);   
        current_item = next_item;
    } 
    return (1);
}

void	do_cmd(t_ps *root, char cmd)
{
	if (cmd == SA)
		swap(root->a);
	if (cmd == SB)
		swap(root->b);
	if (cmd == PA && root->b->count > 0)
		push(root->a, pop(root->b, HEAD), HEAD);
	if (cmd == PB && root->a->count > 0)
		push(root->b, pop(root->a, HEAD), HEAD);
	if (cmd == RA && root->a->count > 1)
		push(root->a, pop(root->a, HEAD), TAIL);
	if (cmd == RB && root->b->count > 1)
		push(root->b, pop(root->b, HEAD), TAIL);
	if (cmd == RRA && root->a->count > 1)
		push(root->a, pop(root->a, TAIL), HEAD);
	if (cmd == RRB && root->b->count > 1)
		push(root->b, pop(root->b, TAIL), HEAD);
	cmd_to_buffer(root, cmd);
}

void	print_cmds(char *cmd)
{
	int		i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == SA)
			ft_printf("SA\n");
		if (cmd[i] == SB)
			ft_printf("SB\n");
		if (cmd[i] == SS)
			ft_printf("SS\n");
		if (cmd[i] == RA)
			ft_printf("RA\n");
		if (cmd[i] == RB)
			ft_printf("RB\n");
		if (cmd[i] == RR)
			ft_printf("RR\n");
		if (cmd[i] == RRA)
			ft_printf("RRA\n");
		if (cmd[i] == RRB)
			ft_printf("RRB\n");
		if (cmd[i] == RRR)
			ft_printf("RRR\n");
	}
}

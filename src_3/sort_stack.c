/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:59:46 by luigi             #+#    #+#             */
/*   Updated: 2024/09/12 15:46:00 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_ps *root, t_stack *stack)
{
	int		*first;
	int		*second;
	int		*third;

	first = take_item(stack, 0);
	second = take_item(stack, 1);
	third = take_item(stack, 2);

	if (first < second && second < third)
		return ;
	if (first > second && first > third)
		do_cmd(root, RA);
	else if (first < second && first > third)
		do_cmd(root, RRA);
	else
		do_cmd(root, SA);
	sort_3(root, stack);
}

void	sort_small(t_ps *root)
{
	int		one;
	int		first;
	int		second;

	first = *take_item(root->b, 0);
	second = *take_item(root->b, 1);
	one = unsorted_one(root->a);
	if (one != -1)
	{
		to_top(root, A, one);
		do_cmd(root, PB);
		to_top(root, A, (one + 1) % root->a->size);
		do_cmd(root, PA);
	}
	while (root->a->count > 3)
		do_cmd(root, PB);
	sort_3(root, root->a);
	while (root->b->count)
	{
		if (root->b->count > 1 && first < second)
			do_cmd(root, SB);
		to_top(root, A, first + 1);
		do_cmd(root, PA);
	}
}

void	sort_big(t_ps *root)
{
	int		partition_size;
	int		partition;
	int		count;
	int		i;

	partition_size = root->a->size / 2;
	partition = 0;
	while (root->a->count)
	{
		i = -1;
		count = root->a->count;
		while (++i < count)
		{
			if (*take_item(root->a, 0) < (partition + 1) * partition_size)
			{
				do_cmd(root, PB);
				if (*take_item(root->b, 0) < partition * partition_size + partition_size / 2)
					do_cmd(root, RB);
			}
			else
				do_cmd(root, RA);
		}
		partition++;
	}
	find_best_insert(root);
}

int		unsorted_one(t_stack *stack)
{
	int		i;
	int		j;
	int		n;
	int		one;

	if (stack->count != 5)
		return (-1);
	one = -1;
	i = -1;
	while (++i < stack->count)
	{
		n = pop(stack, HEAD);
		j = -1;
		while (++j < stack->count)
		{
			if (is_sorted(stack) && one == -1)
				one = n;
			push(stack, pop(stack, HEAD), TAIL);
		}
		push(stack, n, HEAD);
		push(stack, pop(stack, HEAD), TAIL);
	}
	return (one);
}

void	to_top(t_ps *root, char id, int n)
{
	t_stack		*stack;
	int			i;

	stack = root->a;
	if (id == B)
		stack = root->b;
	if (n < 0 || stack->count < 2)
		return ;
	i = -1;
	while (++i < stack->count)
		if (*take_item(stack, i) == n)
			break ;
	if (i > stack->count / 2)
		while (i++ < stack->count)
		{
			if (root->a)
				do_cmd(root, RRA);
			else
				do_cmd(root, RRB);
		}
	else
		while (i-- > 0)
		{
			if (root->a)
				do_cmd(root, RA);
			else
				do_cmd(root, RB);
		}
}

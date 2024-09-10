/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:00:46 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 15:48:50 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_3(t_ps *data, t_stack *stack);
static void		sort_small(t_ps *data);
static int		unsorted_one(t_stack *stack);

void	sort_ab(t_ps *data)
{
	int		size;

	size = data->a->count;
	if (is_sorted(data->a))
		ft_exit(data, false);
	if (size == 2)
		do_cmd(data, SWAP | A);
	else if (size == 3)
		sort_3(data, data->a);
	else if (size <= 5)
		sort_small(data);
	else
		sort_large(data);
	bring_to_top(data, A, 0);
}

static void		sort_3(t_ps *data, t_stack *stack)
{
	if (*peek(stack, 0) < *peek(stack, 1) && *peek(stack, 1) < *peek(stack, 2))
		return ;
	if (*peek(stack, 0) > *peek(stack, 2) && *peek(stack, 0) > *peek(stack, 1))
		do_cmd(data, ROT | stack->id);
	else if (*peek(stack, 0) > *peek(stack, 2) && *peek(stack, 0) < *peek(stack, 1))
		do_cmd(data, REV | stack->id);
	else
		do_cmd(data, SWAP | stack->id);
	sort_3(data, stack);
}

static void		sort_small(t_ps *data)
{
	int		only;

	only = unsorted_one(data->a);
	if (only != -1)
	{
		bring_to_top(data, A, only);
		do_cmd(data, PUSH | B);
		bring_to_top(data, A, (only + 1) % data->a->size);
		do_cmd(data, PUSH | A);
	}
	while (data->a->count > 3)
		do_cmd(data, PUSH | B);
	sort_3(data, data->a);
	while (data->b->count)
	{
		if (data->b->count > 1 && *peek(data->b, 0) < *peek(data->b, 1))
			do_cmd(data, SWAP | B);
		bring_to_top(data, A, *peek(data->b, 0) + 1);
		do_cmd(data, PUSH | A);
	}
}

void	sort_large(t_ps *data)
{
	int		chunk_size;
	int		chunk;
	int		count;
	int		i;

	chunk_size = data->a->size / 2;
	chunk = 0;
	while (data->a->count)
	{
		count = data->a->count;
		i = -1;
		while (++i < count)
		{
			if (*peek(data->a, 0) < (chunk + 1) * chunk_size)
			{
				do_cmd(data, PUSH | B);
				if (*peek(data->b, 0) < chunk * chunk_size + chunk_size / 2)
					do_cmd(data, ROT | B);
			}
			else
				do_cmd(data, ROT | A);
		}
		chunk++;
	}
	smart_insert(data);
}

static int		unsorted_one(t_stack *stack)
{
	int		i;
	int		j;
	int		n;
	int		only;

	if (stack->count != 5)
		return (-1);
	only = -1;
	i = -1;
	while (++i < stack->count)
	{
		n = pop(stack, HEAD);
		j = -1;
		while (++j < stack->count)
		{
			if (is_sorted(stack) && only == -1)
				only = n;
			push(stack, pop(stack, HEAD), TAIL);
		}
		push(stack, n, HEAD);
		push(stack, pop(stack, HEAD), TAIL);
	}
	return (only);
}

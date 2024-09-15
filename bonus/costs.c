/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:10:33 by luigi             #+#    #+#             */
/*   Updated: 2024/09/15 16:50:47 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_insert(t_ps *root)
{
	int		low;
	int		size;
	int		partition;
	int		start;

	partition = -1;
	while (root->b->count)
	{
		size = root->b->size / 4;
		if (size > root->b->count)
			size = root->b->count;
		start = (++partition % 2) * -size;
		while (size)
		{
			low = find_lowest(root, start, --size);
			start -= find_distance(root->b, low);
			if (start < -size || start + size >= root->b->count)
				start = -size;
			to_top(root, A, find_next(root->a, low));
			to_top(root, B, low);
			do_cmd(root, PA);
		}
	}
}

int	find_lowest(t_ps *root, int start, int size)
{
	int		end;
	int		low;
	int		lowest_moves;
	int		moves;

	end = start + size;
	lowest_moves = INT_MAX;
	low = -1;
	while (start <= end)
	{
		moves = calculate_moves(root, *take_item(root->b, start));
		if (moves < lowest_moves)
		{
			lowest_moves = moves;
			low = *take_item(root->b, start);
		}
		start++;
	}
	return (low);
}

int	calculate_moves(t_ps *root, int current)
{
	int		moves_a;
	int		moves_b;

	moves_a = find_distance(root->a, find_next(root->a, current));
	moves_b = find_distance(root->b, current);
	if ((moves_a <= 0 && moves_b >= 0) || (moves_a >= 0 && moves_b <= 0))
		return (ft_abs(moves_a - moves_b));
	if (ft_abs(moves_a) > ft_abs(moves_b))
		return (ft_abs(moves_a));
	return (ft_abs(moves_b));
}

int	find_distance(t_stack *stack, int num)
{
	int		i;

	if (num < 0)
		return (0);
	i = -1;
	while (take_item(stack, ++i))
		if (*take_item(stack, i) == num)
			break ;
	if (i > stack->count / 2)
		return (-1 * (stack->count - i));
	return (i);
}

int	find_next(t_stack *stack, int num)
{
	int		next;
	int		current;
	int		i;

	if (stack->count < 1)
		return (-1);
	next = INT_MAX;
	i = -1;
	while (take_item(stack, ++i))
	{
		current = *take_item(stack, i);
		if (current > num && current < next)
			next = current;
	}
	if (next == INT_MAX)
		return (find_next(stack, -1));
	return (next);
}

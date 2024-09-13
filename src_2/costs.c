/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:06:42 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 16:23:43 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_num_lowest(t_ps *data, int start, int size);
static int	calculate_moves(t_ps *data, int current);
static int	find_next(t_stack *stack, int num);
static int	get_distance(t_stack *stack, int num);

void	smart_insert(t_ps *data)
{
	int		num_lowest;
	int		chunk_size;
	int		chunk;
	int		chunk_start;

	chunk = -1;
	while (data->b->count)
	{
		chunk_size = data->b->size / 4;
		if (chunk_size > data->b->count)
			chunk_size = data->b->count;
		chunk_start = (++chunk % 2) * -chunk_size;
		while (chunk_size)
		{
			num_lowest = get_num_lowest(data, chunk_start, --chunk_size);
			chunk_start -= get_distance(data->b, num_lowest);
			if (chunk_start < -chunk_size
				|| chunk_start + chunk_size >= data->b->count)
				chunk_start = -chunk_size;
			bring_to_top(data, A, find_next(data->a, num_lowest));
			bring_to_top(data, B, num_lowest);
			do_cmd(data, PUSH | A);
		}
	}
}

static int	get_num_lowest(t_ps *data, int start, int size)
{
	int		end;
	int		num_lowest;
	int		lowest_moves;
	int		moves;

	end = start + size;
	lowest_moves = INT_MAX;
	num_lowest = -1;
	while (start <= end)
	{
		moves = calculate_moves(data, *peek(data->b, start));
		if (moves < lowest_moves)
		{
			lowest_moves = moves;
			num_lowest= *peek(data->b, start);
		}
		start++;
	}
	return (num_lowest);
}

static int	calculate_moves(t_ps *data, int current)
{
	int		moves_a;
	int		moves_b;

	moves_a = get_distance(data->a, find_next(data->a, current));
	moves_b = get_distance(data->b, current);
	if ((moves_a <= 0 && moves_b >= 0) || (moves_a >= 0 && moves_b <= 0))
		return (ft_abs(moves_a - moves_b));
	if (ft_abs(moves_a) > ft_abs(moves_b))
		return (ft_abs(moves_a));
	return (ft_abs(moves_b));
}


static int	find_next(t_stack *stack, int num)
{
	int		next;
	int		current;
	int		i;

	if (stack->count < 1)
		return (-1);
	next = INT_MAX;
	i = -1;
	while (peek(stack, ++i))
	{
		current = *peek(stack, i);
		if (current > num && current < next)
			next = current;
	}
	if (next == INT_MAX)
		return (find_next(stack, -1));
	return (next);
}

static int	get_distance(t_stack *stack, int num)
{
	int		i;

	if (num < 0)
		return (0);
	i = -1;
	while (peek(stack, ++i))
		if (*peek(stack, i) == num)
			break ;
	if (i > stack->count / 2)
		return (-1 * (stack->count - i));
	return (i);
}

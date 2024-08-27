/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:25:35 by luigi             #+#    #+#             */
/*   Updated: 2024/08/27 11:52:45 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_rank(t_stack *stack, int size)
{
	t_stack		*sorted_stack;
	t_stack		*current;
	int			i;

	sorted_stack = NULL;
	current = stack;
	i = 0;
	while (i++ < size)
	{
		put_node(&sorted_stack, current->num);
		current = current->next;
	}
	quick_sort_stack(&sorted_stack, 0, size - 1);
	if (!duplicate_check_stack(sorted_stack, size))
		return (free_stack(sorted_stack), 0);
	current = stack;
	i = 0;
	while (i++ < size)
	{
		current->num = binary_search_stack(sorted_stack, current->num, 0, size);
		current = current->next;
	}
	free_stack(sorted_stack);
	return (1);
}

int	partition_stack(t_stack **stack, int low, int high)
{
	t_stack		*pivot_node;
	t_stack		*current;
	int			pivot;
	int			i;
	int			j;

	pivot_node = get_node_at_index(*stack, high);
	pivot = pivot_node->num;
	i = low - 1;
	j = low;
	while (j < high)
	{
		current = get_node_at_index(*stack, j);
		if (current->num <= pivot)
		{
			i++;
			swap_nodes(stack, i, j);
		}
		j++;
	}
	swap_nodes(stack, i + 1, high);
	return (i + 1);
}

t_stack	*get_node_at_index(t_stack *stack, int index)
{
	t_stack		*current;
	int			i;

	i = 0;
	current = stack;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

void	swap_nodes(t_stack **stack, int i, int j)
{
	t_stack		*node_i;
	t_stack		*node_j;
	int			tmp;

	node_i = get_node_at_index(*stack, i);
	node_j = get_node_at_index(*stack, j);
	tmp = node_i->num;
	node_i->num = node_j->num;
	node_j->num = tmp;
}

int	binary_search_stack(t_stack *stack, int target, int low, int high)
{
	t_stack		*mid_node;
	int			mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		mid_node = get_node_at_index(stack, mid);
		if (mid_node->num == target)
			return (mid);
		else if (mid_node->num < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

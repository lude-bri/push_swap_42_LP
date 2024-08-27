/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:51:46 by luigi             #+#    #+#             */
/*   Updated: 2024/08/27 11:52:42 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_stack(t_stack **stack, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition_stack(stack, low, high);
		quick_sort_stack(stack, low, pi - 1);
		quick_sort_stack(stack, pi + 1, high);
	}
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

	i = -1;
	current = stack;
	while (++i < index)
		current = current->next;
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

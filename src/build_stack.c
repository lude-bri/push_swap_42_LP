/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:24:31 by luigi             #+#    #+#             */
/*   Updated: 2024/08/08 12:09:40 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int size)
{
	t_stack		*last_node;

	stack->a_bottom = 0;
	stack->b_bottom = size - 1;
	stack->pivot = size;
	stack->size = size;
	last_node = find_lastnode(stack);
	last_node->next = stack;
	stack->prev = last_node;
}

t_stack *create_stack(char **str)
{
	t_stack		*stack;
	t_stack		*last_node;
	int			count;
	int			i;

	count = number_sanity_check(str);
	if (count == 0)
		return (NULL);
	stack = NULL;
	i = count;
	while (i > 0)
	{
		put_node(&stack, ft_atoi(str[count - i]));
		i--;
	}
	init_stack(stack, count);
	if (!to_rank(stack, stack->size))
			return (free_stack(stack), NULL);
	return (stack);
}

void	put_node(t_stack **stack, int data)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->num = data;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_lastnode(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return ;
}

t_stack	*find_lastnode(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


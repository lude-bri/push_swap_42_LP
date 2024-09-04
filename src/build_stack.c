/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:24:31 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 11:50:38 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int size, t_stack_root *stack_root, int flag)
{
	t_stack			*last_node;
	t_stack			*current;
	int				i;

	i = -1;
	current = stack;
	if (flag == STACK_A)
	{
		stack_root->size_a = size;
		while (++i < size)
		{
			current->a_bottom = 0;
			current->b_bottom = size - 1;
			current->pivot = size;
			current->size = size;
			current = current->next;
		}
		last_node = find_lastnode(stack);
		last_node->next = stack;
		stack->prev = last_node;
	}
	else
		init_stack_b(stack, size, stack_root);
}

void	init_stack_b(t_stack *stack, int size, t_stack_root *stack_root)
{
	t_stack			*last_node;
	t_stack			*current;
	int				i;

	i = -1;
	current = stack;
	stack_root->size_b = 0;
	while (++i < size)
	{
		current->a_bottom = 0;
		current->b_bottom = size - 1;
		current->pivot = size;
		current->size = 0;
		current = current->next;
	}
	last_node = find_lastnode(stack);
	last_node->next = stack;
	stack->prev = last_node;
}

t_stack	*create_stack(char **str, t_stack_root *stack_root, int flag)
{
	t_stack			*stack;
	int				count;
	int				i;

	count = number_sanity_check(str);
	if (count == 0)
		return (NULL);
	stack = NULL;
	i = count;
	stack_root = malloc(sizeof(t_stack_root));
	if (!stack_root)
		return (NULL);
	while (i > 0)
	{
		if (flag == STACK_A)
			put_node(&stack, ft_atoi(str[count - i]));
		else
			put_node(&stack, -1);
		--i;
	}
	init_stack(stack, count, stack_root, flag);
	if (!to_rank(stack, stack->size) && flag == STACK_A)
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

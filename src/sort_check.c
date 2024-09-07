/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:53:35 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:02:25 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b, t_stack_root *stack_root)
{
	t_stack		*current;
	int			i;

	i = -1;
	current = stack_a;
	(void)(*stack_b);
	if (stack_root->size_b != 0)
		return (0);
	while (++i < stack_root->size_a - 1)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}


/*
int	is_a_sorted_n(t_stack **stack, t_stack_root **stack_root, int size)
{
	t_stack	*current;
	int		expected_val;
	int		idx;

	if (size > (*stack_root)->size_a)
		return (0);
	if (size <= 1)
		return (1);
	
	// Começamos de a_bottom e percorremos para trás

	current = (*stack)->prev;  // "this" é o topo da pilha 'a'
	expected_val = current->num;
	idx = 1;

	// Percorre a lista verificando a ordem crescente
	while (idx < size)
	{
		current = current->prev;
		if (current->num != ++expected_val)
			return (0);
		idx++;
	}
	return (1);
}

int	is_b_sorted_n(t_stack **stack, t_stack_root **stack_root, int size)
{
	t_stack	*current;
	int		expected_val;
	int		idx;

	if (size > (*stack_root)->size_b)
		return (0);
	if (size <= 1)
		return (1);
	
	// Começamos de b_bottom e percorremos para frente
	current = (*stack)->next;  // "this" é o topo da pilha 'b'
	expected_val = current->num;
	idx = 1;

	// Percorre a lista verificando a ordem decrescente
	while (idx < size)
	{
		current = current->next;
		if (current->num != --expected_val)
			return (0);
		idx++;
	}
	return (1);
}


*/

int	is_a_sorted(t_stack **stack, t_stack_root **stack_root, int size)
{
	t_stack		*current;
	int			value;
	int			i;

	if (size > (*stack_root)->size_a)
		return (0);
	if (size <= 1)
		return (1);

	current = (*stack)->prev;
	value = current->num;
	i = 1;
	while (i < size)
	{
		current = current->prev;
		if (current->num != ++value)
			return (0);
		i++;
	}
	return (1);
}

int	is_b_sorted(t_stack **stack, t_stack_root **stack_root, int size)
{
	t_stack		*current;
	int			value;
	int			i;

	if (size > (*stack_root)->size_b)
		return (0);
	if (size <= 1)
		return (1);

	current = (*stack)->next;
	value = (*stack)->num;
	i = 0;
	while (++i < size)
	{
		current = current->next;
		if (current->num != --value)
			return (0);
	}
	return (1);
}


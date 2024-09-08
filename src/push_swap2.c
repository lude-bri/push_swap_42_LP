/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:50:37 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 13:52:58 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack, t_stack_root **stack_root)
{
	t_stack *big;

	if  (!*stack)
		return ;
	big = find_big(*stack, (*stack_root)->size_a);
	if (!is_sorted(*stack, (void *)(stack), *stack_root))
	{
		if (*stack == big)
			do_cmd(stack, (void *)(stack), stack_root, RA);
		else if ((*stack)->next == big)
			do_cmd(stack, (void *)(stack), stack_root, RRA);
		if ((*stack)->num > (*stack)->next->num)
			do_cmd(stack, (void *)(stack), stack_root, SA);
	}
}

// void	sort_4(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int dir)
// {
// 	// Divida os 4 elementos na pilha
// 	split_2(stack_a, stack_b, stack_root, 4, dir);
//
// 	// Comparações para ver se precisamos fazer swap
// 	if ((*stack_a)->num < (*stack_a)->next->num
// 		&& (*stack_b)->num < (*stack_b)->next->num)
// 		do_cmd(stack_a, stack_b, stack_root, SS);
// 	else if ((*stack_a)->num < (*stack_a)->next->num)
// 		do_cmd(stack_a, stack_b, stack_root, SA);
// 	else if ((*stack_b)->num < (*stack_b)->next->num)
// 		do_cmd(stack_a, stack_b, stack_root, SB);
//
// 	// Empurre os elementos de volta para a pilha A
// 	do_cmd(stack_a, stack_b, stack_root, PA);
// 	do_cmd(stack_a, stack_b, stack_root, PA);
// }
//
// void	sort_5(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int dir)
// {
// 	// Divida os 5 elementos na pilha
// 	split_2(stack_a, stack_b, stack_root, 5, dir);
//
// 	// Se necessário, faz swap no topo de A
// 	if ((*stack_a)->num < (*stack_a)->next->num)
// 		do_cmd(stack_a, stack_b, stack_root, SA);
//
// 	// Ordena os 3 elementos restantes na pilha B
// 	sort_3b(stack_b, stack_root);
//
// 	// Empurre os elementos de volta para a pilha A
// 	do_cmd(stack_a, stack_b, stack_root, PA);
// 	do_cmd(stack_a, stack_b, stack_root, PA);
// }


int get_pivot(t_stack **stack, t_stack_root *root, int size, int dir)
{
    int max_val = -1;
    int min_val = 2147483647;
    t_stack *current;
    int cur_val;

	(void)(*root);
    if (dir == 0) {  // Assume '0' é para a pilha 'a'
        current = *stack;  // Começa do topo da pilha 'a'
    } else {  // '1' é para a pilha 'b'
        current = *stack;  // Começa do topo da pilha 'b'
    }

    for (int i = 0; i < size; i++) {
        cur_val = current->num;
        if (max_val < cur_val)
            max_val = cur_val;
        if (min_val > cur_val)
            min_val = cur_val;
        current = current->next;  // Move para o próximo elemento na lista circular
    }

    return ((min_val + max_val) >> 1);  // Retorna a média dos valores máximo e mínimo
}




void	sort_4(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int dir)
{
	int			size;
	t_stack		*stack;

	(void)(dir);
	stack = find_small(stack_a, (*stack_root)->size_a);
	if (!*stack_a || !*stack_b)
		return ;
	size = (*stack_root)->size_a;
	while (size > 0)
	{
		if (!is_sorted(*stack_a, *stack_b, *stack_root))
		{	
			if ((*stack_a)->num == stack->num)
			{
				do_cmd(stack_a, stack_b, stack_root, PB);
				break ;
			}
			else
				do_cmd(stack_a, stack_b, stack_root, RA);
		}
		size--;
	}
	sort_3(stack_a, stack_root);
	do_cmd(stack_a, stack_b, stack_root, PA);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int dir)
{
	int			size;
	t_stack		*small;

	(void)(dir);
	if (!*stack_a || !*stack_b)
		return ;
	size = (*stack_root)->size_a;
	small = find_small(stack_a, (*stack_root)->size_a);
	while (size > 0)
	{
		if (!is_sorted(*stack_a, *stack_b, *stack_root))	
		{
			if ((*stack_a)->num == small->num)
				do_cmd(stack_a, stack_b, stack_root, PB);
			else if ((*stack_a)->num == small->num + 1)
				do_cmd(stack_a, stack_b, stack_root, PB);
			else
				do_cmd(stack_a, stack_b, stack_root, RA);
		}
		if ((*stack_b)->num == small->num && (*stack_b)->next->num == small->num + 1)
			break ;
		size--;
	}
	sort_3(stack_a, stack_root);
	if ((*stack_b)->num < (*stack_b)->next->num)
		do_cmd(stack_a, stack_b, stack_root, RB);
	do_cmd(stack_a, stack_b, stack_root, PA);
	do_cmd(stack_a, stack_b, stack_root, PA);
}

t_stack	*find_big(t_stack *stack, int size)
{
	int			n;
	t_stack		*high_node;
	
	if (!stack)
		return (NULL);
	n = 0;
	while (size)
	{
		if (stack->num > n)
		{
			n = stack->num;
			high_node = stack;
		}
		stack = stack->next;
		size--;
	}
	return (high_node);
}

t_stack	*find_small(t_stack **stack, int size)
{
	t_stack		*small_node;
	t_stack		*current;
	int			n;

	if (!stack || size <= 0)
		return (NULL);

	current = (*stack);
	small_node = current;
	n = current->num;
	while (size)
	{
		if (current->num <= n)
		{
			n = current->num;
			small_node = current;
		}
		current = current->next;
		size--;
	}
	return (small_node);
}

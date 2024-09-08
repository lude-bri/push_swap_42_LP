/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:04 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 13:59:18 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ab(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root)
{	
	int		N;
	int		partition_size;
	int		big_pivot;
	//int		small_pivot;

	N = (*stack_root)->size_a;
	partition_size = N / 3;
	big_pivot = (*stack_root)->size_a - partition_size;
	//small_pivot = big_pivot - partition_size;

	if ((*stack_root)->size_a <= 5)
		sort_base_case(stack_a, stack_b, stack_root, (*stack_root)->size_a, 0);
	else
	{
		split_first(stack_a, stack_b, 0, stack_root);
		if (!is_a_sorted(stack_a, stack_root, partition_size))
			quick_a(stack_a, stack_b, stack_root, big_pivot, N);
		//se houver somente 3 elementos na stack A, verifique se estao ordenados
		if ((*stack_root)->size_a == 3 && !is_a_sorted(stack_a, stack_root, 3))
			sort_3(stack_a, stack_root);
		//se estiverem ordenados, passamos para a fase 3
		//se nao estiverem ordenados, ordene com algoritmo de 3.
	
		// while (N)
		// {	
		// 	do_cmd(stack_a, stack_b, stack_root, PA);
		// 	N--;
		// }
	 
		/*if (is_b_sorted(stack_b, stack_root, partition_size))
			push_a_n(stack_a, stack_b, stack_root, N);
		else
			quick_b(stack_a, stack_b, stack_root, small_pivot, big_pivot);
			*/
		
		/*if (is_b_sorted(stack_b, stack_root, small_pivot))
			push_a_n(stack_a, stack_b, stack_root, small_pivot);
		else
			quick_b(stack_a, stack_b, stack_root, 0, small_pivot);
*/
		/*if (!is_a_sorted(stack_a, stack_root, partition_size))
			quick_a(stack_a, stack_b, stack_root, big_pivot, (*stack_root)->size_a);
		if (is_b_sorted(stack_b, stack_root, partition_size))
			push_a_n(stack_a, stack_b, stack_root, partition_size);
		else
			quick_b(stack_a, stack_b, stack_root, small_pivot, big_pivot);
		if (is_b_sorted(stack_b, stack_root, small_pivot))
			push_a_n(stack_a, stack_b, stack_root, small_pivot);
		else
			quick_b(stack_a, stack_b, stack_root, 0, small_pivot);*/
	}
}

void	sort_base_case(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int size, int flag)
{
	if (size == 2 && flag)
		push_a_n(stack_a, stack_b, stack_root, 2);
	if (size == 2 && (*stack_a)->next->num < (*stack_a)->num)
		do_cmd(stack_a, stack_b, stack_root, SA);
	// else if (size == 3 && flag)
	// 	sort_3b(stack_b, stack_root);
	else if (size == 3)
		sort_3(stack_a, stack_root);
	else if (size == 4)
		sort_4(stack_a, stack_b, stack_root, flag);
	else if (size == 5)
		sort_5(stack_a, stack_b, stack_root, flag);
}

// First it is needed to split the numbers in 3. In that case N = 100 --> n = 33. Then N = 33 --> n = 11. Then N = 11 --> n = 4
// Once there is no way to split, its time to go to the phase 3. Therefore
//
//	1. Split first 

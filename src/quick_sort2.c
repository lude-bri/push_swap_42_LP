/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:10:27 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:14:25 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_a(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int start, int end)
{
	int		partition_size = (end - start) / 3;
	int		big_pivot = end - partition_size;
	int		small_pivot = big_pivot - partition_size;

	if (end - start <= 5)
		sort_base_case(stack_a, stack_b, stack_root);
	else
	{
	}

}

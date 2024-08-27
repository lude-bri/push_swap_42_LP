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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:56:53 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 16:06:06 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_insert(t_stack **stack_a, t_stack **stack_b, t_stack_root **root)
{
	int		num_lowest;
	int		chunk_size;
	int		chunk;
	int		chunk_start;

	chunk = -1;
	while ((*root)->size_b)
	{
		chunk_size = (*root)->size_b / 6;
		if (chunk_size > (*root)->size_b)
			chunk_size = (*root)->size_b;
		chunk_start = (++chunk % 3) * -chunk_size;
		while (chunk_size)
		{
			num_lowest = get_lowest()
		}
	}
}

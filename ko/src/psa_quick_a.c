/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_quick_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:23:11 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/19 16:43:36 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

// half open, end not included, O(5 * N / 3)
/*
			||
			||					||
	a_bot	||	a_top . b_top	||||	b_bot
*/
void	split_a3(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end)
{
	const int	partition_size = (end - start) / 3;
	const int	big_pivot = end - partition_size;
	const int	small_pivot = big_pivot - partition_size;
	int			idx;

	idx = -1;
	while (++idx < end - start)
	{
		if (big_pivot <= a_top(pab) && a_top(pab) < end)
			do_cmd(pab, p_cmd_vec, RA);
		else if (small_pivot <= a_top(pab) && a_top(pab) < big_pivot)
		{
			do_cmd(pab, p_cmd_vec, PB);
			do_cmd(pab, p_cmd_vec, RB);
		}
		else
			do_cmd(pab, p_cmd_vec, PB);
	}
	idx = -1;
	while (++idx < partition_size)
		do_cmd(pab, p_cmd_vec, RRR);
}

void	quick_a(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end)
{
	const int	partition_size = (end - start) / 3;
	const int	big_pivot = end - partition_size;
	const int	small_pivot = big_pivot - partition_size;

	if (end - start <= 5)
		sort_base_case(pab, p_cmd_vec, end - start, 0);
	else
	{
		split_a3(pab, p_cmd_vec, start, end);
		if (!is_a_sorted_n(pab, partition_size))
			quick_a(pab, p_cmd_vec, big_pivot, end);
		if (is_b_sorted_n(pab, partition_size))
			push_a_n(pab, p_cmd_vec, partition_size);
		else
			quick_b(pab, p_cmd_vec, small_pivot, big_pivot);
		if (is_b_sorted_n(pab, small_pivot - start))
			push_a_n(pab, p_cmd_vec, small_pivot - start);
		else
			quick_b(pab, p_cmd_vec, start, small_pivot);
	}
}

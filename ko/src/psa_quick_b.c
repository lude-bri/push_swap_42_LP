/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_quick_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:45:16 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/19 16:42:57 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

void	split_b3(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end)
{
	const int	partition_size = (end - start) / 3;
	const int	small_pivot = start + partition_size;
	const int	big_pivot = small_pivot + partition_size;
	int			idx;

	idx = -1;
	while (++idx < end - start)
	{
		if (big_pivot <= b_top(pab) && b_top(pab) < end)
			do_cmd(pab, p_cmd_vec, PA);
		else if (small_pivot <= b_top(pab) && b_top(pab) < big_pivot)
		{
			do_cmd(pab, p_cmd_vec, PA);
			do_cmd(pab, p_cmd_vec, RA);
		}
		else
			do_cmd(pab, p_cmd_vec, RB);
	}
}

void	quick_b(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end)
{
	const int	partition_size = (end - start) / 3;
	const int	small_pivot = start + partition_size;
	const int	big_pivot = small_pivot + partition_size;
	int			idx;

	if (end - start <= 5)
		sort_base_case(pab, p_cmd_vec, end - start, 1);
	else
	{
		split_b3(pab, p_cmd_vec, start, end);
		if (!is_a_sorted_n(pab, end - big_pivot))
			quick_a(pab, p_cmd_vec, big_pivot, end);
		idx = -1;
		while (++idx < partition_size)
			do_cmd(pab, p_cmd_vec, RRR);
		if (!is_a_sorted_n(pab, big_pivot - small_pivot))
			quick_a(pab, p_cmd_vec, small_pivot, big_pivot);
		if (is_b_sorted_n(pab, small_pivot - start))
			push_a_n(pab, p_cmd_vec, partition_size);
		else
			quick_b(pab, p_cmd_vec, start, small_pivot);
	}
}

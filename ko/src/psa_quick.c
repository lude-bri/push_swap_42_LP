/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_quick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:41:54 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/19 16:43:14 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

void	do_cmd(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int cmd)
{
	if (cmd == PA)
		pa(pab);
	else if (cmd == PB)
		pb(pab);
	else if (cmd == RA)
		ra(pab);
	else if (cmd == RB)
		rb(pab);
	else if (cmd == RR)
		rr(pab);
	else if (cmd == RRA)
		rra(pab);
	else if (cmd == RRB)
		rrb(pab);
	else if (cmd == RRR)
		rrr(pab);
	else if (cmd == SA)
		sa(pab);
	else if (cmd == SB)
		sb(pab);
	else if (cmd == SS)
		ss(pab);
	p_cmd_vec->push_back(p_cmd_vec, &cmd);
}

// split first
static void	split_first(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start,
		int end)
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
		else if (start <= a_top(pab) && a_top(pab) < small_pivot)
		{
			do_cmd(pab, p_cmd_vec, PB);
			do_cmd(pab, p_cmd_vec, RB);
		}
		else
			do_cmd(pab, p_cmd_vec, PB);
	}
}

void	sort_ab(t_stack_ab *pab, t_ft_vector *p_cmd_vec)
{
	const int	partition_size = pab->size / 3;
	const int	big_pivot = pab->size - partition_size;
	const int	small_pivot = big_pivot - partition_size;

	if (pab->size <= 5)
		sort_base_case(pab, p_cmd_vec, pab->size, 0);
	else
	{
		split_first(pab, p_cmd_vec, 0, pab->size);
		if (!is_a_sorted_n(pab, partition_size))
			quick_a(pab, p_cmd_vec, big_pivot, pab->size);
		if (is_b_sorted_n(pab, partition_size))
			push_a_n(pab, p_cmd_vec, partition_size);
		else
			quick_b(pab, p_cmd_vec, small_pivot, big_pivot);
		if (is_b_sorted_n(pab, small_pivot))
			push_a_n(pab, p_cmd_vec, small_pivot);
		else
			quick_b(pab, p_cmd_vec, 0, small_pivot);
	}
}

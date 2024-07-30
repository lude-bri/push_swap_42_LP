/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_base2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:57:22 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/19 15:15:45 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

// split2 will be called when the size is 4 or 5.
// so bigger than pivot will alway be 2
// smaller or equal than pivot will be 2 or 3
static void	split_2b(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size,
		const int pivot)
{
	int	idx;

	idx = -1;
	while (++idx < size)
	{
		if (pivot < b_top(pab))
			do_cmd(pab, p_cmd_vec, PA);
		else
			do_cmd(pab, p_cmd_vec, RB);
	}
	idx = -1;
	while (++idx < size - (size >> 1))
		do_cmd(pab, p_cmd_vec, RRB);
}

// keep b bigger than a
// dir == 0 -> left, stack a
// dir == 1 -> right, stack b
static void	split_2(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size, int dir)
{
	const int	pivot = get_pivot(pab, size, dir);
	int			idx;

	if (dir)
		return (split_2b(pab, p_cmd_vec, size, pivot));
	idx = -1;
	while (++idx < size)
	{
		if (pivot < a_top(pab))
			do_cmd(pab, p_cmd_vec, RA);
		else
			do_cmd(pab, p_cmd_vec, PB);
	}
	do_cmd(pab, p_cmd_vec, RRA);
	do_cmd(pab, p_cmd_vec, RRA);
}

// bipart 22 and sort
// dir == 0 -> left, stack a
// dir == 1 -> right, stack b
static void	sort_4(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int dir)
{
	split_2(pab, p_cmd_vec, 4, dir);
	if (pab->pdata[pab->pivot - 2] < a_top(pab)
		&& b_top(pab) < pab->pdata[pab->pivot + 1])
		do_cmd(pab, p_cmd_vec, SS);
	else if (pab->pdata[pab->pivot - 2] < a_top(pab))
		do_cmd(pab, p_cmd_vec, SA);
	else if (b_top(pab) < pab->pdata[pab->pivot + 1])
		do_cmd(pab, p_cmd_vec, SB);
	do_cmd(pab, p_cmd_vec, PA);
	do_cmd(pab, p_cmd_vec, PA);
}

// bipart 23 and sort
// dir == 0 -> left, stack a
// dir == 1 -> right, stack b
static void	sort_5(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int dir)
{
	split_2(pab, p_cmd_vec, 5, dir);
	if (pab->pdata[pab->pivot - 2] < a_top(pab))
		do_cmd(pab, p_cmd_vec, SA);
	sort_3b(pab, p_cmd_vec);
	return ;
}

// optimized insertion sort
// dir == 0 -> left, stack a
// dir == 1 -> right, stack b
void	sort_base_case(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size,
		int dir)
{
	if (size == 2 && dir)
		push_a_n(pab, p_cmd_vec, 2);
	if (size == 2 && pab->pdata[pab->pivot - 2] < a_top(pab))
		do_cmd(pab, p_cmd_vec, SA);
	else if (size == 3 && dir)
		sort_3b(pab, p_cmd_vec);
	else if (size == 3)
		sort_3a(pab, p_cmd_vec);
	else if (size == 4)
		sort_4(pab, p_cmd_vec, dir);
	else if (size == 5)
		sort_5(pab, p_cmd_vec, dir);
}

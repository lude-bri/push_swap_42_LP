/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:41:32 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/20 14:23:32 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

void	push_a_n(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size)
{
	int	idx;

	idx = -1;
	while (++idx < size)
		do_cmd(pab, p_cmd_vec, PA);
}

int	get_pivot(t_stack_ab *pab, int size, int dir)
{
	int	max_val;
	int	min_val;
	int	idx;
	int	cur_val;

	max_val = -1;
	min_val = 2147483647;
	idx = -1;
	while (++idx < size)
	{
		if (dir)
			cur_val = pab->pdata[pab->pivot + idx];
		else
			cur_val = pab->pdata[pab->pivot - 1 - idx];
		if (max_val < cur_val)
			max_val = cur_val;
		if (min_val > cur_val)
			min_val = cur_val;
	}
	return ((min_val + max_val) >> 1);
}

void	sort_3a(t_stack_ab *pab, t_ft_vector *p_cmd_vec)
{
	char		*pattern;
	int			first;
	const int	second = pab->pdata[pab->pivot - 2];
	const int	third = pab->pdata[pab->pivot - 3];

	first = pab->pdata[pab->pivot - 1];
	if (a_size(pab) == 3)
		pattern = get_pattern_3a_roll(first, second, third);
	else if (first < third && third < second)
		pattern = "180";
	else if (second < first && first < third)
		pattern = "8";
	else if (third < first && first < second)
		pattern = "1808";
	else if (second < third && third < first)
		pattern = "8180";
	else if (third < second && second < first)
		pattern = "1140708";
	else
		pattern = "";
	first = -1;
	while (pattern[++first] != '\0')
		do_cmd(pab, p_cmd_vec, pattern[first] - '0');
}

void	sort_3b(t_stack_ab *pab, t_ft_vector *p_cmd_vec)
{
	char		*pattern;
	int			first;
	const int	second = pab->pdata[pab->pivot + 1];
	const int	third = pab->pdata[pab->pivot + 2];

	first = pab->pdata[pab->pivot];
	if (b_size(pab) == 3)
		pattern = get_pattern_3b_roll(first, second, third);
	else if (first > third && third > second)
		pattern = "0900";
	else if (second > first && first > third)
		pattern = "9000";
	else if (third > first && first > second)
		pattern = "09080";
	else if (second > third && third > first)
		pattern = "90900";
	else if (third > second && second > first)
		pattern = "904070";
	else
		pattern = "000";
	first = -1;
	while (pattern[++first] != '\0')
		do_cmd(pab, p_cmd_vec, pattern[first] - '0');
}

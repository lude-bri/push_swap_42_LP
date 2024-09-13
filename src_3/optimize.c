/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:00:36 by luigi             #+#    #+#             */
/*   Updated: 2024/09/12 19:09:18 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize(t_ps *root, char *cmds)
{
	char	*prev;
	char	do_it;
	int		i;

	prev = 0;
	do_it = -1;
	while (!(++do_it) || ft_strncmp(cmds, prev, !!do_it * ft_strlen(cmds)))
	{
		free(prev);
		prev = ft_strdup(cmds);
		i = -1;
		while(cmds[++i])
		{
			optimize_swap(&cmds[i], A);
			optimize_swap(&cmds[i], B);
			if (cmds[i] == PA || cmds[i] == PB)
				clean_push(&cmds[i]);
			if (cmds[i] == SA || cmds[i] == SB)
				clean_swap(&cmds[i]);
			if ((cmds[i] == RRA || cmds[i] == RRB) || (cmds[i] == RA || cmds[i] == RB)
				|| (cmds[i] == RRR) || cmds[i] == RR)
				clean_rotate(&cmds[i], 0, 4, -2);
		}
	}
	free(prev);
	clean_redundance(root, cmds);
}

void	clean_push(char *cmds)
{
	int		count_a;
	int		count_b;
	int		i;

	count_a = 0;
	count_b = 0;
	i = 0;
	while ((cmds[i] == PA) || (cmds[i] == PB) || cmds[i] == TO_CLEAN)
	{
		if (cmds[i] == PA)
			count_a++;
		if (cmds[i] == PB)
			count_b++;
		cmds[i++] = TO_CLEAN;
	}
	i = -1;
	while (++i < ((count_a - count_b) * (count_a > count_b)
			+ (count_b - count_a) * (count_b > count_a)))
		cmds[i] = PA * (count_a > count_b)
			+ PB * (count_b > count_a);
}


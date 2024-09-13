/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:18:52 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:19:54 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rev_rot(char *cmds, int *count, int r)
{
	int i;

	i = 0;
	while (++r < 2)
	{
		while (count[r] || count[r + 1])
		{
			while (cmds[i] != TO_CLEAN)
				i++;
			if (!count[r])
			{
				if (count[1])
					cmds[i++] = RRA;
				else if (count[3])
					cmds[i++] = RRB;
			}
			else if (!count[r + 1])
			{
				if (count[0])
					cmds[i++] = RA;
				else if (count[2])
					cmds[i++] = RB;
			}
			count_update(count, r, !count[r], !count[r + 1]);
		}
	}
}

void	add_swap(int count_a, int count_b, char *cmds)
{
	if (count_a + count_b && (count_a % 2 + count_b % 2))
	{
		cmds[0] = 0;
		if (count_a % 2)
			cmds[0] |= SA;
		if (count_b % 2)
			cmds[0] |= SB;
	}
}

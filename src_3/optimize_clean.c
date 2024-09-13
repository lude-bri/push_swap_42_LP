/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:29:30 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:29:53 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_push(char *cmds)
{
	int		count_a;
	int		count_b;
	int		i;

	count_a = 0;
	count_b = 0;
	i = 0;
	while ((cmds[i] == PA) || (cmds[i] == PB) 
			|| cmds[i] == TO_CLEAN)
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
		cmds[i] = PA * (count_a > count_b) + PB * (count_b > count_a);
}

void clean_swap(char *cmds)
{
    int count_a;
    int count_b;
    int seen[256] = {0};
	int i;

    count_a = 0;
    count_b = 0;
    i = 0;

    while (cmds[i] && !(cmds[i] == PA || cmds[i] == PB) 
			&& !seen[(unsigned char)cmds[i]])
    {
        if (cmds[i] == SA)
            count_a++;
        if (cmds[i] == SB)
            count_b++;

        if (cmds[i] == SA || cmds[i] == SB)
            cmds[i] = TO_CLEAN; // Marca como "limpo"
        else if (cmds[i] != TO_CLEAN)
            seen[(unsigned char)cmds[i]] = 1; // Marca o comando como visto
        i++;
    }
	if (count_a + count_b && (count_a % 2 + count_b % 2))
		add_swap(count_a, count_b, cmds);
}

void	clean_rotate(char *cmds, char seen, int i, int r)
{
	int	count[4];

	while (i > 0)
		count[--i] = 0;
	while (cmds[i] && !(cmds[i] == PA || cmds[i] == PB) && !(cmds[i] == seen))
	{
		count_update(count, cmds[i++], 0, 0);
		if (cmds[i - 1] == RA || cmds[i - 1] == RB 
				|| cmds[i - 1] == RRA || cmds[i - 1] == RRB)
			cmds[i - 1] = TO_CLEAN;
		else if (cmds[i - 1] != TO_CLEAN)
			seen = cmds[i - 1];
	}
	count_update(count, -1, count[0], count[2]);
	add_rev_rot(cmds, count, r);
}



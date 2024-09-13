/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:00:36 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:23:59 by luigi            ###   ########.fr       */
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
			if ((cmds[i] == RRA || cmds[i] == RRB) 
					|| (cmds[i] == RA || cmds[i] == RB)
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

int *count_update(int count[4], int r, int tmp0, int tmp1)
{
    if (r > 4)
    {
        // Contabiliza rotação normal (RA, RB) e reverse (RRA, RRB)
        count[0] += (r == RA);   // Se r é RA, incrementa count[0]
        count[1] += (r == RRA);  // Se r é RRA, incrementa count[1]
        count[2] += (r == RB);   // Se r é RB, incrementa count[2]
        count[3] += (r == RRB);  // Se r é RRB, incrementa count[3]
    }
    else if (r == -1)
    {
        // Ajuste das contagens para as rotações e reverses
        count[0] = (count[0] - count[1]) * (count[0] > count[1]);
        count[1] = (count[1] - tmp0) * (count[1] > tmp0);
        count[2] = (count[2] - count[3]) * (count[2] > count[3]);
        count[3] = (count[3] - tmp1) * (count[3] > tmp1);
    }
    else
    {
        // Ajusta os contadores removendo valores conforme tmp0 e tmp1
        count[0] -= (tmp1 && count[0]);
		count[1] -= (tmp0 && count[1]);
		count[2] -= (tmp1 && count[2]);
		count[3] -= (tmp0 && count[3]);
    }
    return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:00:36 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:46:16 by luigi            ###   ########.fr       */
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

void	optimize_swap(char *cmds, char id)
{
	int	rev;
	int	count;
	int	i;

	rev = 0;
	count = 0;
	i = -1;
	while (cmds[++i] && count < 3)
	{
		if (count == 1 && ((id == A && cmds[i] == RRA) 
			|| (id == B && cmds[i] == RRB)))
			rev = 1;
		if ((count == 0 && ((id == A && cmds[i] == PB) || (id == B && cmds[i] == PA)))
			|| (count == 1 && ((id == A && (cmds[i] == RA || cmds[i] == RRA))
					  || (id == B && (cmds[i] == RB || cmds[i] == RRB))))
			|| (count == 2 && ((id == A && cmds[i] == PA) || (id == B && cmds[i] == PB))))
				count++;
		else if (cmds[i] != TO_CLEAN)
			count = 10;
	}
	if (count == 3)
		add_best(cmds, id, rev);
}

void	optimize_rot(char *cmds, char cmd, int count_id)
{
    int count_r;
    int i;
    int j;

    // Verifica se o primeiro comando é o esperado
    if (cmds[0] != cmd)
        return;

    count_r = 0;
    i = -1;

    // Conta o número de vezes que o comando `cmd` aparece, ignorando `TO_CLEAN`
    while (cmds[++i] == cmd || cmds[i] == TO_CLEAN)
    {
        if (cmds[i] == cmd)
            count_r++;
    }

    j = 0;

    // Substitui os comandos conforme a contagem e o valor de `count_id`
    while (count_r > count_id / 2 && j != i)
    {
        if (count_r != count_id)
        {
            if (cmd == RA)
                cmds[j++] = RRA;  // Troca RA por RRA
            else if (cmd == RB)
                cmds[j++] = RRB;  // Troca RB por RRB
            else if (cmd == RRA)
                cmds[j++] = RA;   // Troca RRA por RA
            else if (cmd == RRB)
                cmds[j++] = RB;   // Troca RRB por RB
            count_r++;
        }
        else
        {
            cmds[j++] = TO_CLEAN;  // Limpa o comando se count_r igual a count_id
        }
    }
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

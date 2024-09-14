/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:45:34 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 17:04:13 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		clean_rot(char *cmds, char vis, int i, int r);
static void		clean_swap(char *cmds);
static void		clean_push(char *cmds);

void	optmize(t_ps *data, char *cmds)
{
	char	*prev;
	int		i;
	char	do_it;

	prev = 0;
	do_it = -1;
	while (!(++do_it) || ft_strncmp(cmds, prev, !!do_it * ft_strlen(cmds)))
	{
		free(prev);
		prev = ft_strdup(cmds);
		i = -1;
		while (cmds[++i])
		{
			replace_manual_swap(&cmds[i], A);
			replace_manual_swap(&cmds[i], B);
			if (cmds[i] & PUSH)
				clean_push(&cmds[i]);
			if (cmds[i] & SWAP)
				clean_swap(&cmds[i]);
			if (cmds[i] & (ROT | REV))
				clean_rot(&cmds[i], 0, 4, -2);
		}
	}
	free(prev);
	too_many_rotations(data, cmds);
}

static void		clean_rot(char *cmds, char vis, int i, int r)
{
	int		count[4];

	while (i > 0)
		count[--i] = 0;
	while (cmds[i] && !(cmds[i] & PUSH) && !(cmds[i] & vis))
	{
		count_helper(count, cmds[i++], 0, 0);
		if ((REV | ROT) & cmds[i - 1])
			cmds[i - 1] = CLEAR;
		else if (cmds[i - 1] != CLEAR)
			vis |= cmds[i - 1];
	}
	count_helper(count, -1, count[0], count[2]);
	i = 0;
	while (++r < 2 && r++ < 2)
	{
		while (count[r] || count[r + 1])
		{
			while (cmds[i] != CLEAR)
				i++;
			cmds[i++] = !count[r] * (REV | (A * !!count[1]) | (B * !!count[3]))
				+ !count[r + 1] * (ROT | (A * !!count[0]) | (B * !!count[2]));
			count_helper(count, r, !count[r], !count[r + 1]);
		}
	}
}

int		*count_helper(int count[4], int r, int tmp0, int tmp1)
{
	if (r > 4)
	{
		count[0] += ((r & ROT) && (r & A));
		count[1] += ((r & REV) && (r & A));
		count[2] += ((r & ROT) && (r & B));
		count[3] += ((r & REV) && (r & B));
	}
	else if (r == -1)
	{
		count[0] = (count[0] - count[1]) * (count[0] > count[1]);
		count[1] = (count[1] - tmp0) * (count[1] > tmp0);
		count[2] = (count[2] - count[3]) * (count[2] > count[3]);
		count[3] = (count[3] - tmp1) * (count[3] > tmp1);
	}
	else
	{
		count[0] -= (tmp1 && count[0]);
		count[1] -= (tmp0 && count[1]);
		count[2] -= (tmp1 && count[2]);
		count[3] -= (tmp0 && count[3]);
	}
	return (count);
}


static void		clean_swap(char *cmds)
{
	int		count_a;
	int		count_b;
	char	vis;
	int		i;

	count_a = 0;
	count_b = 0;
	vis = 0;
	i = 0;
	while (cmds[i] && !(cmds[i] & PUSH) && !(cmds[i] & vis))
	{
		if ((cmds[i] & SWAP) && (cmds[i] & A))
			count_a++;
		if ((cmds[i] & SWAP) && (cmds[i] & B))
			count_b++;
		if (cmds[i] & SWAP)
			cmds[i] = CLEAR;
		else if (cmds[i] != CLEAR)
			vis |= cmds[i];
		i++;
	}
	if (count_a + count_b && (count_a % 2 + count_b % 2))
		cmds[0] = SWAP | (A * (count_a % 2)) | (B * (count_b % 2));
}


static void		clean_push(char *cmds)
{
	int	count_a;
	int	count_b;
	int	i;

	count_a = 0;
	count_b = 0;
	i = 0;
	while ((cmds[i] & PUSH) || cmds[i] == CLEAR)
	{
		if (cmds[i] & A)
			count_a++;
		if (cmds[i] & B)
			count_b++;
		cmds[i++] = CLEAR;
	}
	i = -1;
	while (++i < ((count_a - count_b) * (count_a > count_b)
			+ (count_b - count_a) * (count_b > count_a)))
		cmds[i] = (PUSH | A) * (count_a > count_b)
			+ (PUSH | B) * (count_b > count_a);
}

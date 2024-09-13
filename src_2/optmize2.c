/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmize2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:05:00 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:44:35 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void		insert_swap(char *cmds, char id, int rev);
static void		replace_r(char *cmds, char cmd, int count_id);

void	replace_manual_swap(char *cmds, char id)
{
	int	rev;
	int	count;
	int	i;

	rev = 0;
	count = 0;
	i = -1;
	while (cmds[++i] && count < 3)
	{
		if (count == 1 && cmds[i] == (REV | id))
			rev = 1;
		if ((count == 0 && cmds[i] == (PUSH | (A + B - id)))
			|| (count == 1 && (cmds[i] == (ROT | id) || cmds[i] == (REV | id)))
			|| (count == 2 && cmds[i] == (PUSH | id)))
			count++;
		else if (cmds[i] != CLEAR)
			count = 10;
	}
	if (count == 3)
		insert_swap(cmds, id, rev);
}

void	too_many_rotations(t_ps *data, char *cmds)
{
	static char		action;
	int				count_a;
	int				i;

	count_a = data->a->size;
	i = -1;
	while (cmds[++i])
	{
		count_a += -(cmds[i] == (PUSH | B)) + (cmds[i] == (PUSH | A));
		if ((cmds[i] == (PUSH | B)) || (cmds[i] == (PUSH | A)))
			continue ;
		if (((count_a == 2 && (cmds[i] == (SWAP | A) || cmds[i] == (ROT | A)))
			|| (data->a->size - count_a == 2 && (cmds[i] == (SWAP | B)
					|| cmds[i] == (ROT | B)))) && (++action <= 2))
		{
			cmds[i] = (action * ROT) | ((cmds[i]  | (SWAP | ROT)) ^ (SWAP | ROT));
			optmize(data, cmds);
			return ;
		}
		replace_r(&cmds[i], ROT | A, count_a);
		replace_r(&cmds[i], REV | A, count_a);
		replace_r(&cmds[i], ROT | B, data->a->size - count_a);
		replace_r(&cmds[i], ROT | B, data->a->size - count_a);
	}
}

static void	insert_swap(char *cmds, char id, int rev)
{
	int	count;
	int	i;

	count = -1;
	i = -1;
	while (cmds[++i] && ++count < 3)
	{
		while (cmds[i] == CLEAR)
			i++;
		if (count == 0)
			cmds[i] = rev * (REV | id) + !rev * CLEAR;
		else if (count == 1)
			cmds[i] = SWAP | id;
		else if (count == 2)
			cmds[i] = !rev * (ROT | id) + rev * CLEAR;
	}
}

static void		replace_r(char *cmds, char cmd, int count_id)
{
	int	count_r;
	int	i;
	int	j;

	if (cmds[0] != cmd)
		return ;
	count_r = 0;
	i = -1;
	while (cmds[++i] == cmd || cmds[i] == CLEAR)
		if (cmds[i] == cmd)
			count_r++;
	j = 0;
	while (count_r > count_id / 2 && j != i)
	{
		if (count_r != count_id)
			cmds[j++] = cmd ^ (ROT | REV) + 0 * count_r++;
		else
			cmds[j++] = CLEAR;
	}
}


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

static void	clean_push(char *ops, int i);
static void	clean_swap(char *ops, int i);
static void	clean_rotate(char *ops, int i);
static void	clean_reverse(char *ops, int i);

void	optimize_operations(char *ops)
{
	int		i;
	char	do_it;

	do_it = -1;
	while (!(++do_it))
	{
		i = -1;
		while (ops[++i])
		{
			if (ops[i] == PB)
				clean_push(ops, i);
			else if (ops[i] == SA || ops[i] == SB)
				clean_swap(ops, i);
			else if (ops[i] == RA || ops[i] == RB)
				clean_rotate(ops, i);
			else if (ops[i] == RRA || ops[i] == RRB)
				clean_reverse(ops, i);
		}
	}
}

static void	clean_push(char *ops, int i)
{
	if ((ops[i] == PB && ops[i + 1] == RA && ops[i + 2] == PA)
		|| (ops[i + 1] == PA && ops[i + 2] == RA))
	{
		ops[i] = SA;
		ops[i + 1] = TO_CLEAN;
		ops[i + 2] = TO_CLEAN;
	}
	else if (ops[i] == PB && ops[i + 1] == PB && ops[i + 2] == PA)
	{
		ops[i] = PB;
		ops[i + 1] = TO_CLEAN;
		ops[i + 2] = TO_CLEAN;
	}
	else if (ops[i] == PB && ops[i + 1] == PA && ops[i + 2] == PB)
	{
		ops[i + 1] = TO_CLEAN;
		ops[i + 2] = TO_CLEAN;
	}
}

static void	clean_swap(char *ops, int i)
{
	if ((ops[i] == SA && ops[i + 1] == SB)
		|| (ops[i] == SB && ops[i + 1] == SA))
	{
		ops[i] = SS;
		ops[i + 1] = TO_CLEAN;
	}
}

static void	clean_rotate(char *ops, int i)
{
	if (ops[i] == RA && ops[i + 1] == RB)
	{
		ops[i] = RR;
		ops[i + 1] = TO_CLEAN;
	}
	else if (ops[i] == RB && ops[i + 1] == RA)
	{
		ops[i] = RR;
		ops[i + 1] = TO_CLEAN;
	}
	else if (ops[i] == RA && ops[i + 1] == RA
		&& (ops[i + 2] == RRA || ops[i + 2] == RRA))
	{
		ops[i] = RA;
		ops[i + 1] = TO_CLEAN;
		ops[i + 2] = TO_CLEAN;
	}
	else if (ops[i] == RA && ops[i + 1] == RRA)
	{
		ops[i] = TO_CLEAN;
		ops[i + 1] = TO_CLEAN;
	}
}

static void	clean_reverse(char *ops, int i)
{
	if (ops[i] == RRA && ops[i + 1] == RRB)
	{
		ops[i] = RRR;
		ops[i + 1] = TO_CLEAN;
	}
	else if (ops[i] == RRB && ops[i + 1] == RRA)
	{
		ops[i] = RRR;
		ops[i + 1] = TO_CLEAN;
	}
}

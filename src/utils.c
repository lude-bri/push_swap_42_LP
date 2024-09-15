/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:21:01 by luigi             #+#    #+#             */
/*   Updated: 2024/09/15 14:21:19 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top_2(t_ps *root, t_stack *stack, char id, int i)
{
	if (i > stack->count / 2)
	{
		while (i++ < stack->count)
		{
			if (id == A)
				do_cmd(root, RRA);
			else if (id == B)
				do_cmd(root, RRB);
		}
	}
	else
	{
		while (i-- > 0)
		{
			if (id == A)
				do_cmd(root, RA);
			else if (id == B)
				do_cmd(root, RB);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/19 16:09:54 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_command.h"

// command optimize
// failed -1, succeed macro value
static int	merge_command(int cmd1, int cmd2)
{
	if ((cmd1 == RA && cmd2 == RB) || (cmd1 == RB && cmd2 == RA))
		return (RR);
	else if ((cmd1 == RRA && cmd2 == RRB) || (cmd1 == RRB && cmd2 == RRA))
		return (RRR);
	else if ((cmd1 == SA && cmd2 == SB) || (cmd1 == SB && cmd2 == SA))
		return (SS);
	else if ((cmd1 == PA && cmd2 == PB) || (cmd1 == PB && cmd2 == PA)
		|| (cmd1 == RA && cmd2 == RRA) || (cmd1 == RRA && cmd2 == RA)
		|| (cmd1 == RB && cmd2 == RRB) || (cmd1 == RRB && cmd2 == RB))
		return (-1);
	else
		return (-2);
}

// command decode
char	*decode_command(int cmd)
{
	if (cmd == PA)
		return ("pa\n");
	else if (cmd == PB)
		return ("pb\n");
	else if (cmd == RA)
		return ("ra\n");
	else if (cmd == RB)
		return ("rb\n");
	else if (cmd == RR)
		return ("rr\n");
	else if (cmd == RRA)
		return ("rra\n");
	else if (cmd == RRB)
		return ("rrb\n");
	else if (cmd == RRR)
		return ("rrr\n");
	else if (cmd == SA)
		return ("sa\n");
	else if (cmd == SB)
		return ("sb\n");
	else
		return ("ss\n");
}

void	print_command_buffer(t_ft_vector *this)
{
	int			idx;
	int			merged_cmd;
	const int	*pdata = this->pbuffer;

	idx = -1;
	while (++idx < (int)this->size)
	{
		if (idx < (int)this->size - 1)
		{
			merged_cmd = merge_command(pdata[idx], pdata[idx + 1]);
			if (merged_cmd >= 0)
			{
				idx++;
				ft_putstr_fd(decode_command(merged_cmd), 1);
			}
			else if (merged_cmd == -1)
				idx++;
			else
				ft_putstr_fd(decode_command(pdata[idx]), 1);
		}
		else
			ft_putstr_fd(decode_command(pdata[idx]), 1);
	}
}

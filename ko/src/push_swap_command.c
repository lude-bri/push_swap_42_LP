/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:58:59 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/15 13:49:04 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_command.h"

int	set_int(void *paddr, void *pval)
{
	*(int *)paddr = *(int *)pval;
	return (1);
}

// do nothing
void	free_int(void *paddr)
{
	paddr++;
}

t_ft_vector	*new_command_buffer(void)
{
	return (new_ftvec(set_int, free_int, sizeof(int)));
}

void	delete_command_buffer(t_ft_vector *this)
{
	delete_ftvec(this);
}

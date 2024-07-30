/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:01:15 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/12 20:54:41 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	pa(t_stack_ab *this)
{
	if (b_size(this) != 0)
	{
		this->pivot++;
	}
}

void	pb(t_stack_ab *this)
{
	if (a_size(this) != 0)
	{
		this->pivot--;
	}
}

// swap
void	sa(t_stack_ab *this)
{
	int	tmp;

	if (a_size(this) > 1)
	{
		tmp = this->pdata[this->pivot - 1];
		this->pdata[this->pivot - 1] = this->pdata[this->pivot - 2];
		this->pdata[this->pivot - 2] = tmp;
	}
}

void	sb(t_stack_ab *this)
{
	int	tmp;

	if (b_size(this) > 1)
	{
		tmp = this->pdata[this->pivot + 1];
		this->pdata[this->pivot + 1] = this->pdata[this->pivot];
		this->pdata[this->pivot] = tmp;
	}
}

void	ss(t_stack_ab *this)
{
	sa(this);
	sb(this);
}

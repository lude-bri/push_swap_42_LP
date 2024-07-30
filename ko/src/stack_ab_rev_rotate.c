/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:22:01 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/12 20:53:24 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	rra(t_stack_ab *this)
{
	int	idx;
	int	tmp;

	if (a_size(this) <= 0)
		return ;
	idx = this->a_bot;
	tmp = this->pdata[idx];
	while (idx < this->pivot - 1)
	{
		this->pdata[idx] = this->pdata[idx + 1];
		idx++;
	}
	this->pdata[this->pivot - 1] = tmp;
}

void	rrb(t_stack_ab *this)
{
	int	idx;
	int	tmp;

	if (b_size(this) <= 0)
		return ;
	idx = this->b_bot;
	tmp = this->pdata[idx];
	while (idx > this->pivot)
	{
		this->pdata[idx] = this->pdata[idx - 1];
		idx--;
	}
	this->pdata[this->pivot] = tmp;
}

void	rrr(t_stack_ab *this)
{
	rra(this);
	rrb(this);
}

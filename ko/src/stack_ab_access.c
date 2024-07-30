/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:01:20 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/15 15:27:21 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

int	a_top(t_stack_ab *this)
{
	if (a_size(this) > 0)
		return (this->pdata[this->pivot - 1]);
	return (-1);
}

int	b_top(t_stack_ab *this)
{
	if (b_size(this) > 0)
		return (this->pdata[this->pivot]);
	return (-1);
}

int	a_bot(t_stack_ab *this)
{
	if (a_size(this) > 0)
		return (this->pdata[this->a_bot]);
	return (-1);
}

int	b_bot(t_stack_ab *this)
{
	if (b_size(this) > 0)
		return (this->pdata[this->b_bot]);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:38 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/16 16:49:44 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

// check b empty.
// check a ordered.
int	is_ab_sorted(t_stack_ab *this)
{
	int	idx;

	idx = -1;
	if (b_size(this) != 0)
		return (0);
	while (++idx < this->size)
	{
		if (this->pdata[idx] != this->size - 1 - idx)
		{
			return (0);
		}
	}
	return (1);
}

int	is_a_sorted_n(t_stack_ab *this, int size)
{
	int	idx;
	int	expected_val;

	if (size > a_size(this))
		return (0);
	if (size <= 1)
		return (1);
	idx = 0;
	expected_val = a_top(this);
	while (++idx < size)
	{
		if (this->pdata[this->pivot - 1 - idx] != ++expected_val)
			return (0);
	}
	return (1);
}

int	is_b_sorted_n(t_stack_ab *this, int size)
{
	int	idx;
	int	expected_val;

	if (size > b_size(this))
		return (0);
	if (size <= 1)
		return (1);
	idx = 0;
	expected_val = b_top(this);
	while (++idx < size)
	{
		if (this->pdata[this->pivot + idx] != --expected_val)
			return (0);
	}
	return (1);
}

int	a_size(t_stack_ab *this)
{
	return (this->pivot - this->a_bot);
}

int	b_size(t_stack_ab *this)
{
	return (this->b_bot - this->pivot + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:59:46 by luigi             #+#    #+#             */
/*   Updated: 2024/09/11 09:13:22 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_ps *root, t_stack *stack)
{
	int		*first;
	int		*second;
	int		*third;

	first = take_item(stack, 0);
	second = take_item(stack, 1);
	third = take_item(stack, 2);

	if (first < second && second < third)
		return ;
	if (first > second && first > third)
		do_cmd(root, RA);
	else if (first < second && first > third)
		do_cmd(root, RRA);
	else
		do_cmd(root, SA);
	sort_3(root, stack);
}

void	sort_small(t_ps *root)
{
	int		
}


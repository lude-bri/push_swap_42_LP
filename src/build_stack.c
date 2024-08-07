/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:24:31 by luigi             #+#    #+#             */
/*   Updated: 2024/08/07 10:32:10 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(char **str)
{
	t_stack		*stack;
	const int	count;
	int			i;

	count = number_sanity_check(str);
	if (count == 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = malloc(sizeof(int) * count);
	if (!stack->num)
		return (free(stack), NULL);
	i = count;
	while (i >= 0)

}

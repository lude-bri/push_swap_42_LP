/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:36:01 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 14:39:06 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(t_ps *data)
{
	int		i;

	i = 0;
	while (data->split && data->split[i])
		free(data->split[i++]);
	free(data->split);
	data->split = 0;
}

void	free_stack(t_stack *stack)
{
	if (stack)
		free(stack->values);
	free(stack);
}

void	ft_exit(t_ps *data, bool error)
{
	free_split(data);
	free(data->cmds);
	free_stack(data->a);
	free_stack(data->b);
	free(data);
	if (error)
		ft_putstr_fd("Error\n", 2);
	exit(error);
}

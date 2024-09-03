/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:37:57 by luigi             #+#    #+#             */
/*   Updated: 2024/08/07 09:41:12 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_stack(t_stack *stack)
{
	t_stack		*current;
	t_stack		*next;

	current = stack;
	if (stack)
	{
		while ((current->next != stack) && (current->next != NULL))
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(current);
	}
}

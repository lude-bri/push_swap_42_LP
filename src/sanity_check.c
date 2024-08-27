/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:34 by luigi             #+#    #+#             */
/*   Updated: 2024/08/07 11:22:33 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid(char *str)
{
	const int	start = ft_find_start(str);
	const int	len = ft_strlen(str) - start;

	if (len == 10)
	{
		if (str[0] == '-')
			return (ft_strncmp(str + start, "2147483647", 10) <= 0);
		else
			return (ft_strncmp(str + start, "2147483647", 10) <= 0);
	}
	else if (len < 10)
		return (1);
	else
		return (0);
}

int	ft_find_start(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	number_sanity_check(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_is_number(str[i++]))
			return (0);
	i = 0;
	while (str[i])
		if (!ft_is_valid(str[i++]))
			return (0);
	return (i);
}

int	duplicate_check_stack(t_stack *stack, int size)
{
	t_stack		*current;
	t_stack		*runner;
	int			i;
	int			j;

	current = stack;
	i = 0;
	while (i < size)
	{
		runner = current->next;
		j = i + 1;
		while (j < size)
		{
			if (current->num == runner->num)
				return (0);
			runner = runner->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (1);
}

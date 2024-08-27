/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:22:04 by dogwak            #+#    #+#             */
/*   Updated: 2024/08/27 12:01:25 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(const char *str)
{
	int	idx;

	idx = -1;
	if (str[0] == '-' || str[0] == '+')
		idx = 0;
	while (str[++idx] != '\0')
		if (!ft_isdigit(str[idx]))
			return (0);
	return (1);
}

static int	get_number_start(const char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] == '0')
		idx++;
	return (idx);
}

static int	is_in_range(const char *str)
{
	const int	start_pos = get_number_start(str);
	const int	num_len = ft_strlen(str) - start_pos;

	if (num_len == 10)
	{
		if (str[0] == '-')
			return (ft_strncmp(str + start_pos, "2147483648", 10) <= 0);
		else
			return (ft_strncmp(str + start_pos, "2147483647", 10) <= 0);
	}
	else if (num_len < 10)
		return (1);
	else
		return (0);
}

int	ascii_number_sanity_check(const char **strs)
{
	int	idx;

	idx = -1;
	while (strs[++idx] != NULL)
		if (!is_number(strs[idx]))
			return (0
	idx = -1;
	while (strs[++idx] != NULL)
		if (!is_in_range(strs[idx]))
			return (0);
	return (idx);
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


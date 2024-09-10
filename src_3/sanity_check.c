/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:34:04 by luigi             #+#    #+#             */
/*   Updated: 2024/09/10 20:05:31 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_sanity_check(char **str)
{
	int		i;

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

int duplicate_check(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}


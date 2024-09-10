/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:08:18 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 14:42:25 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		count_input(t_ps *data, int ac, char **av)
{
	int		empty;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		empty = 1;
		while (av[i][j] == ' ')
			j++;
		while (av[i][++j - 1])
		{
			if (ft_strchr("0123456789", av[i][j - 1]))
				empty = 0;
			if (av[i][j - 1] == ' ' && av[i][j - 1] != ' ' && av[i][j] != '\0')
				data->a->size++;
		}
		if (empty)
			ft_exit(data, true);
		data->a->size++;
	}
	data->b->size = data->a->size;
}

static void	check_valid_number(t_ps *data, char *str)
{
	int		first_non_zero;
	int		i;
	int		num;

	first_non_zero = 0;
	if (str[first_non_zero] == '+' || str[first_non_zero == '-'])
		first_non_zero++;
	while (str[first_non_zero] == '0')
		first_non_zero++;
	i = -1;
	while(str[++i])
	{
		if (!ft_strchr("0123456789-+", str[i]))
			ft_exit(data, true);
		if (ft_strchr("-+", str[i]) && (!ft_strchr("0123456789", str[i + 1])
				|| (i > 0 && str[i - 1] != ' ')))
			ft_exit(data, true);
	}
	num = ft_atoi(str);
	if (i - first_non_zero > 9 && (num == -1 || num == 0))
		ft_exit(data, true);
	i = -1;
	while (++i < data->a->count)
		if (data->b->values[i] == num)
			ft_exit(data, true);
}

static void		normalize(t_stack *a, t_stack *b)
{
	long long	min;
	long long	low;
	int			lowest;
	int			i;
	int			j;

	min = LLONG_MIN;
	i = 0;
	while (i < a->count)
	{
		j = -1;
		low = LLONG_MAX;
		while (++j < a->count)
		{
			if (b->values[j] < low && b->values[j] > min)
			{
				low = b->values[j];
				lowest = j;
			}
		}
		min = low;
		a->values[lowest] = i++;
	}
	a->tail = a->count - 1;
}

void	get_input(t_ps *data, int ac, char **av)
{
	int		i;
	int		j;

	count_input(data, ac, av);
	data->a->values = malloc(data->a->size * sizeof(int));
	data->b->values = malloc(data->b->size * sizeof(int));
	if (!data->a->values || !data->b->values)
		ft_exit(data, true);
	i = 0;
	while (++i < ac)
	{
		data->split = ft_split(av[i], ' ');
		j = -1;
		while (data->split[++j])
		{
			check_valid_number(data, data->split[j]);
			data->b->values[data->a->count++] = ft_atoi(data->split[j]);
		}
		free_split(data);
	}
	if (data->a->size < 2)
		ft_exit(data, false);
	normalize(data->a, data->b);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:29:05 by luigi             #+#    #+#             */
/*   Updated: 2024/09/10 13:19:35 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	char		**numbers;
	t_ps		*root;

	if (ac == 1)
		exit (0);
	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (*numbers == NULL)
			exit (0);
		root = new_ab(numbers);
		free_strs(numbers);
	}
	else
	{
		numbers = av + 1;
		root = new_ab(numbers);
	}
	if (!root)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	//push_swap(root);
	free_ab(root);
}

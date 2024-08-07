/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:28:58 by luigi             #+#    #+#             */
/*   Updated: 2024/08/07 09:35:20 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1. parse
//2. create stack
//3. resolve push_swap




int	main(int ac, char **av)
{
	char		**numbers;
	t_stack		*stack;

	if (ac == 1)
		exit (0);
	if (ac == 2)
	{
		//parsing
	}
	else
	{
		numbers = av + 1;
		stack = create_stack(numbers);
	}
	if (!stack)
	{
		ft_putstr_fd("Error creating stack\n", 0);
		exit(1);
	}
	push_swap(stack);
	delete_stack(stack);
}

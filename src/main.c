/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:28:58 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 13:49:43 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char			**numbers;
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack_root	*stack_root;

	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!*numbers)
			exit(0);
		stack_root = NULL;
		stack_a = create_stack(numbers, stack_root, STACK_A);
		stack_b = create_stack(numbers, stack_root, STACK_B);
		free_str(numbers);
	}
	else
	{
		numbers = av + 1;
		stack_root = NULL;
		stack_a = create_stack(numbers, stack_root, STACK_A);
		stack_b = create_stack(numbers, stack_root, STACK_B);
	}
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 0);
		exit(1);
	}
	if (!is_sorted(stack_a, stack_b))
		sort_ab(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_root);
}

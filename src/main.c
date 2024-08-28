/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:28:58 by luigi             #+#    #+#             */
/*   Updated: 2024/08/07 09:52:58 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//
// void	is_string(char **av, t_stack *stack_a, t_stack *stack_b)
// {
// 	char		**numbers;
//
// 	numbers = ft_split(av[1], ' ');
// 	if (!*numbers)
// 		exit(0);
// 	stack_a = create_stack(numbers, STACK_A);
// 	stack_b = create_stack(numbers, STACK_B);
// 	free_str(numbers);
// }

int	main(int ac, char **av)
{
	char		**numbers;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!*numbers)
			exit(0);
		stack_a = create_stack(numbers, STACK_A);
		stack_b = create_stack(numbers, STACK_B);
		free_str(numbers);
	}
	else
	{
		numbers = av + 1;
		stack_a = create_stack(numbers, STACK_A);
		stack_b = create_stack(numbers, STACK_B);
	}
	if (!stack_a)
	{
		ft_putstr_fd("Error creating stack\n", 0);
		exit(1);
	}
	if (!is_sorted(stack_a, stack_b))
		sort_ab(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

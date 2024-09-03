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

void print_list(t_stack **list)
{
	t_stack *head = (*list);
	
	do{
		printf("%d\n", head->num);
		head = head->next;
	} while ((*list) != head);
}

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
		ft_putstr_fd("Error\n", 0);
		exit(1);
	}
	if (!is_sorted(stack_a, stack_b))
		sort_ab(&stack_a, &stack_b);
	//
	print_list(&stack_a);
	//
	free_stack(stack_a);
	free_stack(stack_b);
}

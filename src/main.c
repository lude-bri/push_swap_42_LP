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

t_stack_root	*init_root(t_stack *stack_a)
{
	t_stack_root	*root;
	t_stack			*current;
	t_stack			*next;
	int				size;

	root = malloc(sizeof(t_stack_root));
	if (!root)
		return (NULL);
	current = stack_a;
	size = 0;
	while ((current->next != stack_a) && (current->next != NULL))
	{
		next = current->next;
		size++;
		current = next;
	}
	root->size_a = size + 1;
	root->size_b = 0;
	return (root);
}

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
		stack_a = create_stack(numbers, STACK_A);
		stack_b = create_stack(numbers, STACK_B);
		stack_root = init_root(stack_a);
		free_str(numbers);
}
	else
	{
		numbers = av + 1;
		stack_a = create_stack(numbers, STACK_A);
		stack_b = create_stack(numbers, STACK_B);
		stack_root = init_root(stack_a);
	}
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 0);
		exit(1);
	}
	if (!is_sorted(stack_a, stack_b, stack_root))
		sort_ab(&stack_a, &stack_b, &stack_root);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_root);
}

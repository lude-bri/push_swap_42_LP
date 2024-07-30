/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:42:12 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/20 16:02:15 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"
#include "push_swap_parser.h"
#include "stack_ab.h"

void	delete_strs(char **strs)
{
	int	idx;

	idx = -1;
	while (strs[++idx] != NULL)
		free(strs[idx]);
	free(strs);
}

void	solve_push_swap(t_stack_ab *pab)
{
	t_ft_vector	*p_cmd_buffer;

	p_cmd_buffer = new_command_buffer();
	if (p_cmd_buffer == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		delete_ab(pab);
		exit(1);
	}
	if (!is_ab_sorted(pab))
		sort_ab(pab, p_cmd_buffer);
	print_command_buffer(p_cmd_buffer);
	delete_command_buffer(p_cmd_buffer);
}

int	main(int argc, char *argv[])
{
	char		**tokens;
	t_stack_ab	*pab;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (*tokens == NULL)
			exit(0);
		pab = new_ab(tokens);
		delete_strs(tokens);
	}
	else
	{
		tokens = argv + 1;
		pab = new_ab(tokens);
	}
	if (pab == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	solve_push_swap(pab);
	delete_ab(pab);
}

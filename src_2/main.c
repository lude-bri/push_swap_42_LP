/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:34:45 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 17:22:49 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps		*init_data(void);
static void		print_cmds(char *ops);

int		main(int ac, char **av)
{
	t_ps	*data;

	if (ac == 1)
		return (0);
	data = init_data();
	get_input(data, ac, av);
	sort_ab(data);
	optmize(data, data->cmds);
	print_cmds(data->cmds);
	ft_exit(data, false);
}

static t_ps		*init_data(void)
{
	t_ps	*data;

	data = malloc(sizeof(t_ps));
	if (!data)
		return (NULL);
	data->a = init_stack(data, A);
	data->b = init_stack(data, B);
	data->cmds = NULL;
	data->split = NULL;
	return (data);
}

t_stack		*init_stack(t_ps *data, char id)
{
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_exit(data, true);
	stack->id = id;
	stack->values = NULL;
	stack->head = HEAD;
	stack->tail = TAIL;
	stack->count = 0;
	stack->size = 0;
	return(stack);
	
}

static void	print_cmds(char *ops)
{
	int		i;
	char	op;

	i = -1;
	while (ops && ops[++i])
	{
		op = ops[i];
		if (op & SWAP)
			printf("s%c\n", 'a' + !!(op & B) + 17 * !!(op & A && op & B));
		else if (op & PUSH)
			printf("p%c\n", 'a' + !!(op & B));
		else if (op & ROT)
			printf("r%c\n", 'a' + !!(op & B) + 16 * !!(op & A && op & B));
		else if (op & REV)
			printf("rr%c\n", 'a' + !!(op & B) + 16 * !!(op & A && op & B));
	}
}


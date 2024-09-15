/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:23:55 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 16:57:38 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		set_stack(t_ps *root, int count);

t_ps	*new_ab(char **str)
{
	t_ps		*root;
	int			i;
	int			count;

	count = number_sanity_check(str);
	if (!count)
		return (NULL);
	root = init_root();
	if (!root)
		return (NULL);
	root->a->values = malloc(sizeof(int) * count);
	root->b->values = malloc(sizeof(int) * count);
	if (!root->a->values || !root->b->values)
		return (free_ab(root), NULL);
	i = -1;
	while (++i < count && str[i])
		root->b->values[i] = ft_atoi(str[i]);
	set_stack(root, count);
	if (duplicate_check(root->b->values, count) == 0)
		return (free_ab(root), NULL);
	if (!normalize(root->a, root->b))
		return (free_ab(root), NULL);
	return (root);
}

static void	set_stack(t_ps *root, int count)
{
	root->a->size = count;
	root->b->size = count;
	root->a->count = count;
}

int	normalize(t_stack *a, t_stack *b)
{
	int		min;
	int		low;
	int		lowest;
	int		i;
	int		j;

	min = INT_MIN;
	i = 0;
	while (a->size > i)
	{
		j = -1;
		low = INT_MAX;
		while (a->size > ++j)
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
	a->tail = a->size - 1;
	return (1);
}

t_ps	*init_root(void)
{
	t_ps	*root;

	root = malloc(sizeof(t_ps));
	if (!root)
		return (NULL);
	root->a = init_stack(root, A);
	root->b = init_stack(root, B);
	root->cmds = NULL;
	return (root);
}

t_stack	*init_stack(t_ps *root, char id)
{
	t_stack		*stack;

	(void)(root);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free_ab(root), NULL);
	stack->id = id;
	stack->values = NULL;
	stack->count = 0;
	stack->size = 0;
	stack->head = HEAD;
	stack->tail = TAIL;
	return (stack);
}

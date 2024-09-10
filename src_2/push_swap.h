/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:26:37 by luigi             #+#    #+#             */
/*   Updated: 2024/09/09 17:07:30 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../lib/libft_42/libft.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define A 1
# define B 2
# define SWAP 4
# define PUSH 8
# define ROT 16
# define REV 32
# define CLEAR 64

# define HEAD 0
# define TAIL -1

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_stack
{
	char	id;
	int		*values;
	int		head;
	int		tail;
	int		count;
	int		size;
}			t_stack;

typedef	struct s_ps
{
	t_stack	*a;
	t_stack *b;
	char	*cmds;
	char	**split;
}			t_ps;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

void		get_input(t_ps *data, int ac, char **av);

t_stack		*init_stack(t_ps *data, char id);
int			*peek(t_stack *stack, int index);
void		push(t_stack *stack, int value, int where);
int			pop(t_stack *stack, int where);
int			*count_helper(int count[4], int r, int tmp0, int tmp1);

void		sort_ab(t_ps *data);
void		sort_large(t_ps *data);
void		smart_insert(t_ps *data);
void		do_cmd(t_ps *data, char cmd);
void		optmize(t_ps *data, char *cmd);
void		ft_exit(t_ps *data, bool error);
void		free_split(t_ps *data);
void		free_stack(t_stack *stack);


bool		is_sorted(t_stack *stack);
void		bring_to_top(t_ps *data, char id, int n);


void		replace_manual_swap(char *cmds, char id);
void		too_many_rotations(t_ps *data, char *cmds);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:01:45 by luigi             #+#    #+#             */
/*   Updated: 2024/09/15 14:21:59 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../lib/libft_42/libft.h"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define A 1
# define B 2

# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define SA 11
# define SB 12
# define SS 13

# define HEAD 0
# define TAIL -1

# define TO_CLEAN 14 

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_stack
{
	char	id;
	int		*values;
	int		count;
	int		size;
	int		head;
	int		tail;
}			t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	char	*cmds;
}			t_ps;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

//main.c
void	push_swap(t_ps *root);
int		is_sorted(t_stack *stack);

//parser.c
t_ps	*new_ab(char **str);
t_ps	*init_root(void);
t_stack	*init_stack(t_ps *root, char id);
int		normalize(t_stack *a, t_stack *b);

//sanit_check.c
int		duplicate_check(int *arr, int size);
int		ft_is_number(char *str);
int		ft_find_start(char *str);
int		ft_is_valid(char *str);
int		number_sanity_check(char **str);

//push_swap.c
void	do_cmd(t_ps *stack, char cmd);
void	print_cmds(char *cmd);

//basic_cmds.c
void	push(t_stack *stack, int value, int position);
int		pop(t_stack *stack, int position);
void	swap(t_stack *stack);
void	cmd_to_buffer(t_ps *root, char cmd);
int		*take_item(t_stack *stack, int i);

//sort_stack.c
void	sort_3(t_ps *data, t_stack *stack);
void	sort_small(t_ps *root);
int		unsorted_one(t_stack *stack);
void	sort_big(t_ps *data);
void	to_top(t_ps *root, char id, int n);

//free.c
void	free_ab(t_ps *stack);
void	free_strs(char **strs);

//costs.c
void	find_best_insert(t_ps *root);
int		find_lowest(t_ps *root, int start, int size);
int		calculate_moves(t_ps *root, int current);
int		find_next(t_stack *stack, int num);
int		find_distance(t_stack *stack, int num);

//optimize.c
void	optimize_operations(char *ops);

//utils.c
void	to_top_2(t_ps *root, t_stack *stack, char id, int i);

#endif

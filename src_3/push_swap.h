/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:01:45 by luigi             #+#    #+#             */
/*   Updated: 2024/09/10 12:29:53 by luigi            ###   ########.fr       */
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

# define PA 00
# define PB 01
# define RA 02
# define RB 03
# define RR 04
# define RRA 05
# define RRB 06
# define RRR 07
# define SA 8
# define SB 9
# define SS 10

# define HEAD 0
# define TAIL -1


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
	t_stack *b;
	char	*cmds;
	char	**split;
}			t_ps;


/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */


//main.c


//parser.c
t_ps	*new_ab(char **str);
int  normalize(t_stack *a, t_stack *b);
t_ps		*init_root(void);
t_stack		*init_stack(t_ps *root, char id);

//sanit_check.

int		duplicate_check(int *arr, int size);
int		ft_is_number(char *str);
int		ft_find_start(char *str);
int		ft_is_valid(char *str);
int		number_sanity_check(char **str);


//free.c
void	free_ab(t_ps *stack);
void	free_strs(char **strs);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:56:09 by luigi             #+#    #+#             */
/*   Updated: 2024/08/23 14:03:42 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//create double linked list

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "../lib/libft_42/libft.h"

# define STACK_A 1
# define STACK_B 0

typedef struct s_stack
{
	int				num;
	int				size;
	int				a_bottom;
	int				b_bottom;
	int				pivot;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void		init_stack(t_stack *stack, int size);
t_stack		*create_stack(char **str, int flag);
void		put_node(t_stack **stack, int data);
t_stack		*find_lastnode(t_stack *lst);
void		free_str(char **str);
void		free_stack(t_stack *stack);
int			ft_is_valid(char *str);
int			ft_find_start(char *str);
int			ft_is_number(char *str);
int			number_sanity_check(char **str);
int			to_rank(t_stack *stack, int size);
void		quick_sort_stack(t_stack **stack, int low, int high);
int			partition_stack(t_stack **stack, int low, int high);
t_stack		*get_node_at_index(t_stack *stack, int index);
void		swap_nodes(t_stack **stack, int i, int j);
int			duplicate_check_stack(t_stack *stack, int size);
int			binary_search_stack(t_stack *stack, int target, int low, int high);
void		push_swap(t_stack *stack_a, t_stack *stack_b);
int			is_sorted(t_stack *stack_a, t_stack *stack_b);
int			sort_ab(t_stack *stack_a, t_stack *stack_b);
int			a_size(t_stack *stack);
int			b_size(t_stack *stack);
void		is_string(char **av, t_stack *stack_a, t_stack *stack_b);

#endif

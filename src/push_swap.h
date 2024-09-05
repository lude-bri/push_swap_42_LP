/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:56:09 by luigi             #+#    #+#             */
/*   Updated: 2024/09/02 14:56:17 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////
///      MACROS         ///
//////////////////////////

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


////////////////////////////
//      STRUCTURES		///
///////////////////////////

typedef struct s_stack
{
	int				num;
	int				a_bottom;
	int				b_bottom;
	int				pivot;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_root
{
	int			size_a;
	int			size_b;
}	t_stack_root;


////////////////////////////
//   FILES FUNCTIONS	 //
///////////////////////////

//main
t_stack_root	*init_root(t_stack *stack_a);

//build_stack
void		init_stack(t_stack *stack, int size);
t_stack		*create_stack(char **str, int flag);
void		put_node(t_stack **stack, int data);
t_stack		*find_lastnode(t_stack *lst);

//free
void		free_str(char **str);
void		free_stack(t_stack *stack);

//sanity_check
int			ft_is_valid(char *str);
int			ft_find_start(char *str);
int			ft_is_number(char *str);
int			number_sanity_check(char **str);
int			duplicate_check_stack(t_stack *stack, int size);

//normalize
int			to_rank(t_stack *stack, int size);
int			binary_search_stack(t_stack *stack, int target, int low, int high);

//quick_sort
void		quick_sort_stack(t_stack **stack, int low, int high);
int			partition_stack(t_stack **stack, int low, int high);
t_stack		*get_node_at_index(t_stack *stack, int index);
void		swap_nodes(t_stack **stack, int i, int j);

//push_swap
int			is_sorted(t_stack *stack_a, t_stack *stack_b, t_stack_root *stack_root);
void		sort_ab(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root);
void		sort_base_case(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root);
void		split_first(t_stack **stack_a, t_stack **stack_b, int start, t_stack_root **stack_root);

//push_swap2
void		sort_3(t_stack **stack_a, t_stack_root **stack_root);
void		sort_4(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root);
void		sort_5(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root);
t_stack		*find_big(t_stack *stack, int size);

//stack_access
int			a_top(t_stack **stack, t_stack_root **stack_root);
int			b_top(t_stack **stack, t_stack_root **stack_root);
int			a_bottom(t_stack **stack, t_stack_root **stack_root);
int			b_bottom(t_stack **stack, t_stack_root **stack_root);

// commands
void		do_push_cmd(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root, int cmd);
void		do_cmd(t_stack **stack, t_stack_root **stack_root, int cmd);
void		print_cmd(int cmd);

//push_operations
void		pa(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root);
void		pb(t_stack **stack_a, t_stack **stack_b, t_stack_root **stack_root);
void		if_empty(t_stack **stack);

//rotate_operations
void		ra(t_stack **stack);
void		rb(t_stack **stack);
void		rr(t_stack **stack);

//reverse_rotate_operations
void		rra(t_stack **stack);
void		rrb(t_stack **stack);
void		rrr(t_stack **stack);

//swap_operations
void		sa(t_stack **stack, t_stack_root **stack_root);
void		sb(t_stack **stack, t_stack_root **stack_root);
void		ss(t_stack **stack, t_stack_root **stack_root);

#endif

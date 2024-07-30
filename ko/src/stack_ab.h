/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:05:13 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/16 16:44:24 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_H
# define STACK_AB_H

// top of a equals (pivot - 1)
// top of b equals pivot
// bottom of a is 0
// bottom of b is size-1
// so, if b is empty, a_top equals b_bot
typedef struct s_stack_ab
{
	int		size;
	int		a_bot;
	int		b_bot;
	int		pivot;
	int		*pdata;
}			t_stack_ab;

// construct ab stack.
// parser module needed
t_stack_ab	*new_ab(char **strs);
void		delete_ab(t_stack_ab *this);

// utility
int			is_ab_sorted(t_stack_ab *this);
int			is_a_sorted_n(t_stack_ab *this, int size);
int			is_b_sorted_n(t_stack_ab *this, int size);
int			a_size(t_stack_ab *this);
int			b_size(t_stack_ab *this);

// access
int			a_top(t_stack_ab *this);
int			b_top(t_stack_ab *this);
int			a_bot(t_stack_ab *this);
int			b_bot(t_stack_ab *this);

// stack maniputation.
// push
void		pa(t_stack_ab *this);
void		pb(t_stack_ab *this);

// swap
void		sa(t_stack_ab *this);
void		sb(t_stack_ab *this);
void		ss(t_stack_ab *this);

// rotate
void		ra(t_stack_ab *this);
void		rb(t_stack_ab *this);
void		rr(t_stack_ab *this);

// reverse rotate
void		rra(t_stack_ab *this);
void		rrb(t_stack_ab *this);
void		rrr(t_stack_ab *this);

#endif

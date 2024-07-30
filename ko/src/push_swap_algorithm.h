/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:57:11 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/20 13:42:47 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGORITHM_H
# define PUSH_SWAP_ALGORITHM_H

# include "../ft_vector/ft_vector.h"
# include "stack_ab.h"

// execute command and save the command
void	do_cmd(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int cmd);
void	push_a_n(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size);
int		get_pivot(t_stack_ab *pab, int size, int dir);

// pattern for optimized 3 element.
char	*get_pattern_3a_roll(int first, int second, int third);
char	*get_pattern_3b_roll(int first, int second, int third);

// optimized insertion
// base case
void	sort_3a(t_stack_ab *pab, t_ft_vector *p_cmd_vec);
void	sort_3b(t_stack_ab *pab, t_ft_vector *p_cmd_vec);
void	sort_base_case(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size,
			int dir);

// quick + insertion
// recursively
// [), half open, end not included
void	split_a3(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end);
void	quick_a(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end);

void	split_b3(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end);
void	quick_b(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end);

// sort
void	sort_ab(t_stack_ab *pab, t_ft_vector *p_cmd_vec);

#endif

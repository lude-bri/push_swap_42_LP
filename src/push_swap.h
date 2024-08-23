/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:56:09 by luigi             #+#    #+#             */
/*   Updated: 2024/08/08 12:03:27 by luigi            ###   ########.fr       */
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

typedef struct s_stack
{
	int				num;
	int				size;
	int				a_bottom;
	int				b_bottom;
	int				pivot;
	size_t			rank;
	struct s_list	*next;
	struct s_list	*prev;
}	t_stack;

const void init_stack(t_stack *stack, int size);
t_stack *create_stack(char **str);
void	free_str(char **str);
void	free_stack(t_stack *stack);







#endif

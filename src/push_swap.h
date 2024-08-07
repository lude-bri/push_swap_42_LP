/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:56:09 by luigi             #+#    #+#             */
/*   Updated: 2024/08/07 09:43:55 by luigi            ###   ########.fr       */
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

INT_MAX	2147483647


typedef struct s_list
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

#endif

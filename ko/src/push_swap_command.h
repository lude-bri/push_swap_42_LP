/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:58:14 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/15 15:23:39 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMAND_H
# define PUSH_SWAP_COMMAND_H

# include "../ft_vector/ft_vector.h"

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define RR 4
# define RRA 5
# define RRB 6
# define RRR 7
# define SA 8
# define SB 9
# define SS 10

// wrapper function for integer vector.
t_ft_vector	*new_command_buffer(void);
void		delete_command_buffer(t_ft_vector *this);

char		*decode_command(int cmd);
void		print_command_buffer(t_ft_vector *this);

#endif

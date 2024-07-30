/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_base3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/20 14:24:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"

char	*get_pattern_3a_roll(int first, int second, int third)
{
	if (first < second && second < third)
		return ("");
	else if (second < first && first < third)
		return ("8");
	else if (first < third && third < second)
		return ("58");
	else if (second < third && third < first)
		return ("2");
	else if (third < first && first < second)
		return ("5");
	else if (third < second && second < first)
		return ("85");
	else
		return (NULL);
}

char	*get_pattern_3b_roll(int first, int second, int third)
{
	if (first < second && second < third)
		return ("96000");
	else if (first < third && third < second)
		return ("3000");
	else if (second < first && first < third)
		return ("6000");
	else if (third < first && first < second)
		return ("9000");
	else if (second < third && third < first)
		return ("0900");
	else if (third < second && second < first)
		return ("000");
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:00:36 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:46:16 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void optimize_operations(t_ps *root, char *ops) 
{
	char	*prev;
	int		i;
	char	do_it;

	(void)(root);
	prev = 0;
	do_it = -1;
    while (!(++do_it) || ft_strncmp(ops, prev, !!do_it * ft_strlen(ops)))
	{
		free(prev);
		prev = ft_strdup(ops);
		i = -1;
		while (ops[++i])
		{
			// Detecta padrão pb - ra - pa → sa
			if (ops[i] == PB && ops[i + 1] == RA && ops[i + 2] == PA) {
				ops[i] = SA;  // Substitui por sa
				ops[i + 1] = TO_CLEAN;
				ops[i + 2] = TO_CLEAN;
			}

			if (ops[i] == PB && ops[i + 1] == PA && ops[i + 2] == RA) {
				ops[i] = SA;  // Substitui por sa
				ops[i + 1] = TO_CLEAN;
				ops[i + 2] = TO_CLEAN;
			}

			else if (ops[i] == PB && ops[i + 1] == PB && ops[i + 2] == PA) {
				ops[i] = PB;
				ops[i + 1] = TO_CLEAN;
				ops[i + 2] = TO_CLEAN;
			}

			// Detecta e remove operações de push consecutivas opostas (pb - pa - pb → pb)
			else if (ops[i] == PB && ops[i + 1] == PA && ops[i + 2] == PB) {
				ops[i + 1] = TO_CLEAN;
				ops[i + 2] = TO_CLEAN;// Limpa o pa
			}
			
			else if (ops[i] == PB && ops[i + 1] == PB && ops[i + 2] == PA) {
				ops[i] = PB;
				ops[i + 1] = TO_CLEAN;  
				ops[i + 2] = TO_CLEAN;// Limpa o pa
			}

			// Detecta e combina swaps individuais (sa - sb → ss)
			else if (ops[i] == SA && ops[i + 1] == SB) {
				ops[i] = SS;  // Substitui por ss
				ops[i + 1] = TO_CLEAN;
			}

			else if (ops[i] == SB && ops[i + 1] == SA) {
				ops[i] = SS;
				ops[i + 1] = TO_CLEAN;
			}

			// Detecta e combina rotações (ra - rb → rr)
			else if (ops[i] == RA && ops[i + 1] == RB) {
				ops[i] = RR;  // Substitui por rr
				ops[i + 1] = TO_CLEAN;
			}

			else if (ops[i] == RB && ops[i + 1] == RA)
			{
				ops[i] = RR;
				ops[i + 1] = TO_CLEAN;
			}

			// Otimiza rotações: ra - ra - rra → ra (evita gerar rra desnecessário)
			else if (ops[i] == RA && ops[i + 1] == RA && (ops[i + 2] == RRA || ops[i + 2] == RRA)) {
				// Mantém apenas um ra e limpa os outros comandos
				ops[i] = RA;
				ops[i + 1] = TO_CLEAN;
				ops[i + 2] = TO_CLEAN;
			}

			// Evita adicionar RRA extra ou desnecessário
			else if (ops[i] == RA && ops[i + 1] == RRA) {
				// Se há uma rotação seguida imediatamente por uma reversa, elas se cancelam
				ops[i] = TO_CLEAN;
				ops[i + 1] = TO_CLEAN;
			}

			// Detecta e combina rotações reversas (rra - rrb → rrr)
			else if (ops[i] == RRA && ops[i + 1] == RRB) {
				ops[i] = RRR;  // Substitui por rrr
				ops[i + 1] = TO_CLEAN;
			}

			else if (ops[i] == RRB && ops[i + 1] == RRA) {
				ops[i] = RRR;
				ops[i + 1] = TO_CLEAN;
			}


		}

    }
	free(prev);
	//too_many_rotations(root, ops);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:18:52 by luigi             #+#    #+#             */
/*   Updated: 2024/09/13 18:46:26 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	add_rev_rot(char *cmds, int *count, int r)
// {
// 	int i;
//
// 	i = 0;
// 	while (++r < 2)
// 	{
// 		while (count[r] || count[r + 1])
// 		{
// 			while (cmds[i] != TO_CLEAN)
// 				i++;
// 			if (!count[r])
// 			{
// 				if (count[1])
// 					cmds[i++] = RRA;
// 				else if (count[3])
// 					cmds[i++] = RRB;
// 			}
// 			else if (!count[r + 1])
// 			{
// 				if (count[0])
// 					cmds[i++] = RA;
// 				else if (count[2])
// 					cmds[i++] = RB;
// 			}
// 			count_update(count, r, !count[r], !count[r + 1]);
// 		}
// 	}
// }



void add_rev_rot(char *cmds, int *count, int r)
{
    int i;
    int cmds_len;  // Para limitar a iteração de 'i'
    int safety_counter;  // Para evitar um loop infinito

    i = 0;
    cmds_len = ft_strlen(cmds);  // Obtém o comprimento de 'cmds'
    safety_counter = 0;  // Inicializa o contador de segurança

    while (++r < 2)
    {
        while (count[r] || count[r + 1])
        {
            while (cmds[i] != TO_CLEAN)
            {
                i++;
                if (i >= cmds_len || ++safety_counter > cmds_len * 2)
                {
                    // Se ultrapassarmos o limite de iteração, saímos do loop
                    return;
                }
            }
            
            if (!count[r])
            {
                if (count[1])
                    cmds[i++] = RRA;
                else if (count[3])
                    cmds[i++] = RRB;
            }
            else if (!count[r + 1])
            {
                if (count[0])
                    cmds[i++] = RA;
                else if (count[2])
                    cmds[i++] = RB;
            }

            count_update(count, r, !count[r], !count[r + 1]);

            // Reinicia o contador de segurança após uma iteração bem-sucedida
            safety_counter = 0;
        }
    }
}

void	add_swap(int count_a, int count_b, char *cmds)
{
	if (count_a + count_b && (count_a % 2 + count_b % 2))
	{
		cmds[0] = 0;
		if (count_a % 2)
			cmds[0] |= SA;
		if (count_b % 2)
			cmds[0] |= SB;
	}
}

void	add_best(char *cmds, char id, int rev)
{
    int count;
    int i;

    count = -1;
    i = -1;

    // Percorre os comandos até encontrar três não `TO_CLEAN`
    while (cmds[++i] && ++count < 3)
    {
        while (cmds[i] == TO_CLEAN)
            i++;
        
        // Para o primeiro comando, insere RRA/RRB (se `rev` for 1) ou limpa (`TO_CLEAN`)
        if (count == 0)
        {
            if (rev)
            {
                if (id == A)
                    cmds[i] = RRA;
                else if (id == B)
                    cmds[i] = RRB;
            }
            else
            {
                cmds[i] = TO_CLEAN;
            }
        }
        // Para o segundo comando, insere SA ou SB dependendo de `id`
        else if (count == 1)
        {
            if (id == A)
                cmds[i] = SA;
            else if (id == B)
                cmds[i] = SB;
        }
        // Para o terceiro comando, insere RA/RB (se `rev` for 0) ou limpa (`TO_CLEAN`)
        else if (count == 2)
        {
            if (!rev)
            {
                if (id == A)
                    cmds[i] = RA;
                else if (id == B)
                    cmds[i] = RB;
            }
            else
            {
                cmds[i] = TO_CLEAN;
            }
        }
    }
}


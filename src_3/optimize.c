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

static void clean_rot(char *cmds, char vis, int i, int r);
static void clean_swap(char *cmds);
static void clean_push(char *cmds);
static int *count_helper(int count[4], int r, int tmp0, int tmp1);
static void replace_manual_swap(char *cmds, char id);
static void too_many_rotations(t_ps *data, char *cmds);
static void insert_swap(char *cmds, char id, int rev);
static void replace_r(char *cmds, char cmd, int count_id);


void optimize_operations(t_ps *root, char *ops) 
{
	char	*prev;
	int		i;
	char	do_it;

	(void)(*root);
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
			
			// Detecta e remove operações de push consecutivas opostas (pb - pa - pb → pb)
			else if (ops[i] == PB && ops[i + 1] == PA && ops[i + 2] == PB) {
				ops[i + 1] = TO_CLEAN;  // Limpa o pa
			}

			// Detecta e combina swaps individuais (sa - sb → ss)
			else if (ops[i] == SA && ops[i + 1] == SB) {
				ops[i] = SS;  // Substitui por ss
				ops[i + 1] = TO_CLEAN;
			}

			// Detecta e combina rotações (ra - rb → rr)
			else if (ops[i] == RA && ops[i + 1] == RB) {
				ops[i] = RR;  // Substitui por rr
				ops[i + 1] = TO_CLEAN;
			}

			// Otimiza rotações: ra - ra - rra → ra (evita gerar rra desnecessário)
			else if (ops[i] == RA && ops[i + 1] == RA && ops[i + 2] == RRA) {
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

			// Incrementa o índice e limpa comandos TO_CLEAN
			/*if (ops[i] == TO_CLEAN) {
				for (int j = i; j < size - 1; j++) {
					ops[j] = ops[j + 1];  // Move os comandos para frente
				}
				size--;  // Diminui o tamanho da fila
			}*/
		}
    }
}

// void optimize_operations(char *ops) 
// {
//     int i = 0;
//     int	size = ft_strlen(ops);
//
//     while (i < size) {
//         // Detecta padrão pb - ra - pa → sa
//         if (ops[i] == PB && ops[i + 1] == RA && ops[i + 2] == PA) {
//             ops[i] = SA;  // Substitui por sa
//             ops[i + 1] = TO_CLEAN;
//             ops[i + 2] = TO_CLEAN;
//         }
//         
//         // Detecta e remove operações de push consecutivas opostas (pb - pa - pb → pb)
//         else if (ops[i] == PB && ops[i + 1] == PA && ops[i + 2] == PB) {
//             ops[i + 1] = TO_CLEAN;  // Limpa o pa
//         }
//
//         // Detecta e combina swaps individuais (sa - sb → ss)
//         else if (ops[i] == SA && ops[i + 1] == SB) {
//             ops[i] = SS;  // Substitui por ss
//             ops[i + 1] = TO_CLEAN;
//         }
//
//         // Detecta e combina rotações (ra - rb → rr)
//         else if (ops[i] == RA && ops[i + 1] == RB) {
//             ops[i] = RR;  // Substitui por rr
//             ops[i + 1] = TO_CLEAN;
//         }
//
//         // Otimiza rotações (ra - ra - rra → ra)
//         else if (ops[i] == RA && ops[i + 1] == RA && ops[i + 2] == RRA) {
//             ops[i] = RA;  // Substitui por ra
//             ops[i + 1] = TO_CLEAN;
//             ops[i + 2] = TO_CLEAN;
//         }
//
//         // Detecta e combina rotações reversas (rra - rrb → rrr)
//         else if (ops[i] == RRA && ops[i + 1] == RRB) {
//             ops[i] = RRR;  // Substitui por rrr
//             ops[i + 1] = TO_CLEAN;
//         }
//
//         // Incrementa o índice e limpa comandos TO_CLEAN
//         if (ops[i] == TO_CLEAN) {
//             for (int j = i; j < size - 1; j++) {
//                 ops[j] = ops[j + 1];  // Move os comandos
//             }
//             size--;  // Diminui o tamanho da fila
//         } else {
//             i++;
//         }
//     }
// }



void	optimize(t_ps *data, char *cmds)
{
	char	*prev;
	int		i;
	char	do_it;

	prev = 0;
	do_it = -1;
	while (!(++do_it) || ft_strncmp(cmds, prev, !!do_it * ft_strlen(cmds)))
	{
		free(prev);
		prev = ft_strdup(cmds);
		i = -1;
		while (cmds[++i])
		{
			replace_manual_swap(&cmds[i], A);
			replace_manual_swap(&cmds[i], B);
			if (cmds[i] == PA || cmds[i] == PB)
				clean_push(&cmds[i]);
			if (cmds[i] == SA || cmds[i] == SB)
				clean_swap(&cmds[i]);
			if (cmds[i] == RA || cmds[i] == RB || cmds[i] == RRA || cmds[i] == RRB)
				clean_rot(&cmds[i], 0, 4, -2);
		}
	}
	free(prev);
	too_many_rotations(data, cmds);
}

static void clean_rot(char *cmds, char vis, int i, int r)
{
	int count[4];

	while (i > 0)
		count[--i] = 0;
	while (cmds[i] && cmds[i] != PA && cmds[i] != PB && cmds[i] != vis)
	{
		count_helper(count, cmds[i++], 0, 0);
		if (cmds[i - 1] == RRA || cmds[i - 1] == RRB || cmds[i - 1] == RA || cmds[i - 1] == RB)
			cmds[i - 1] = TO_CLEAN;
		else if (cmds[i - 1] != TO_CLEAN)
			vis = cmds[i - 1];
	}
	count_helper(count, -1, count[0], count[2]);
	i = 0;
	while (++r < 2 && r++ < 2)
	{
		while (count[r] || count[r + 1])
		{
			while (cmds[i] != TO_CLEAN)
				i++;
			if (!count[r])
			{
				if (count[1])
					cmds[i++] = RRA;
				else if (count[3])
					cmds[i++] = RRB;
			}
			else
			{
				if (count[0])
					cmds[i++] = RA;
				else if (count[2])
					cmds[i++] = RB;
			}
			count_helper(count, r, !count[r], !count[r + 1]);
		}
	}
}

static void clean_swap(char *cmds)
{
	int count_a;
	int count_b;
	char vis;
	int i;

	count_a = 0;
	count_b = 0;
	vis = 0;
	i = 0;
	while (cmds[i] && cmds[i] != PA && cmds[i] != PB && cmds[i] != vis)
	{
		if (cmds[i] == SA)
			count_a++;
		if (cmds[i] == SB)
			count_b++;
		if (cmds[i] == SA || cmds[i] == SB)
			cmds[i] = TO_CLEAN;
		else if (cmds[i] != TO_CLEAN)
			vis = cmds[i];
		i++;
	}
	if (count_a + count_b && (count_a % 2 + count_b % 2))
	{
		cmds[0] = (count_a % 2) ? SA : SB;
	}
}


static void clean_push(char *cmds)
{
	int count_a;
	int count_b;
	int i;

	count_a = 0;
	count_b = 0;
	i = 0;
	while ((cmds[i] == PA || cmds[i] == PB) || cmds[i] == TO_CLEAN)
	{
		if (cmds[i] == PA)
			count_a++;
		if (cmds[i] == PB)
			count_b++;
		cmds[i++] = TO_CLEAN;
	}
	i = -1;
	while (++i < ((count_a - count_b) * (count_a > count_b) + (count_b - count_a) * (count_b > count_a)))
		cmds[i] = (count_a > count_b) ? PA : PB;
}


static int *count_helper(int count[4], int r, int tmp0, int tmp1)
{
	if (r > 4)
	{
		count[0] += (r == RA);
		count[1] += (r == RRA);
		count[2] += (r == RB);
		count[3] += (r == RRB);
	}
	else if (r == -1)
	{
		count[0] = (count[0] - count[1]) * (count[0] > count[1]);
		count[1] = (count[1] - tmp0) * (count[1] > tmp0);
		count[2] = (count[2] - count[3]) * (count[2] > count[3]);
		count[3] = (count[3] - tmp1) * (count[3] > tmp1);
	}
	else
	{
		count[0] -= (tmp1 && count[0]);
		count[1] -= (tmp0 && count[1]);
		count[2] -= (tmp1 && count[2]);
		count[3] -= (tmp0 && count[3]);
	}
	return count;
}


static void replace_manual_swap(char *cmds, char id)
{
	int rev;
	int count;
	int i;

	rev = 0;
	count = 0;
	i = -1;
	while (cmds[++i] && count < 3)
	{
		if (count == 1 && (cmds[i] == RRA || cmds[i] == RRB))
			rev = 1;
		if ((count == 0 && cmds[i] == ((id == A) ? PB : PA))
			|| (count == 1 && (cmds[i] == ((id == A) ? RA : RB) || cmds[i] == ((id == A) ? RRA : RRB)))
			|| (count == 2 && cmds[i] == ((id == A) ? PA : PB)))
			count++;
		else if (cmds[i] != TO_CLEAN)
			count = 10;
	}
	if (count == 3)
		insert_swap(cmds, id, rev);
}




void too_many_rotations(t_ps *data, char *cmds)
{
	static char action;
	int count_a;
	int i;

	count_a = data->a->size;
	i = -1;
	while (cmds[++i])
	{
		// Ajusta a contagem de elementos em 'a'
		count_a += -(cmds[i] == PB) + (cmds[i] == PA);
		if (cmds[i] == PB || cmds[i] == PA)
			continue;

		// Verifica se há comandos rra e rrb consecutivos para combinar em rrr
		if (cmds[i] == RRA && cmds[i + 1] == RRB)
		{
			// Combina rra e rrb em rrr
			cmds[i] = RRR;
			cmds[i + 1] = TO_CLEAN;  // Marca o próximo comando como limpo
		}
		else if (((count_a == 2 && (cmds[i] == SA || cmds[i] == RA)) ||
			(data->a->size - count_a == 2 && (cmds[i] == SB || cmds[i] == RB))) && (++action <= 2))
		{
			// Define o comando correspondente
			cmds[i] = (action == 1) ? RA : RRA;
			optimize(data, cmds);
			return;
		}

		// Substituição de rotações
		replace_r(&cmds[i], RA, count_a);
		replace_r(&cmds[i], RRA, count_a);
		replace_r(&cmds[i], RB, data->a->size - count_a);
		replace_r(&cmds[i], RRB, data->a->size - count_a);
	}
}

static void insert_swap(char *cmds, char id, int rev)
{
	int count;
	int i;

	count = -1;
	i = -1;

	while (cmds[++i] && ++count < 3)
	{
		while (cmds[i] == TO_CLEAN)
			i++;
		if (count == 0)
		{
			if (rev)
				cmds[i] = (id == A) ? RRA : RRB;
			else
				cmds[i] = TO_CLEAN;
		}
		else if (count == 1)
			cmds[i] = (id == A) ? SA : SB;
		else if (count == 2)
		{
			if (!rev)
				cmds[i] = (id == A) ? RA : RB;
			else
				cmds[i] = TO_CLEAN;
		}
	}
}


static void replace_r(char *cmds, char cmd, int count_id)
{
	int count_r;
	int i;
	int j;

	if (cmds[0] != cmd)
		return;

	count_r = 0;
	i = -1;

	// Conta a quantidade de rotações encontradas
	while (cmds[++i] == cmd || cmds[i] == TO_CLEAN)
		if (cmds[i] == cmd)
			count_r++;

	j = 0;

	// Ajusta as rotações conforme a contagem
	while (count_r > count_id / 2 && j != i)
	{
		if (count_r != count_id)
		{
			if (cmd == RA)
				cmds[j++] = RRA;
			else if (cmd == RB)
				cmds[j++] = RRB;
			else if (cmd == RRA)
				cmds[j++] = RA;
			else if (cmd == RRB)
				cmds[j++] = RB;
			count_r++;
		}
		else
			cmds[j++] = TO_CLEAN;
	}
}






















































/*
void	optimize(t_ps *root, char *cmds)
{
	char	*prev;
	char	do_it;
	int		i;

	prev = 0;
	do_it = -1;
	while (!(++do_it) || ft_strncmp(cmds, prev, !!do_it * ft_strlen(cmds)))
	{
		free(prev);
		prev = ft_strdup(cmds);
		i = -1;
		while(cmds[++i])
		{
			optimize_swap(&cmds[i], A);
			optimize_swap(&cmds[i], B);
			if (cmds[i] == PA || cmds[i] == PB)
				clean_push(&cmds[i]);
			if (cmds[i] == SA || cmds[i] == SB)
				clean_swap(&cmds[i]);
			if ((cmds[i] == RRA || cmds[i] == RRB) 
					|| (cmds[i] == RA || cmds[i] == RB)
				|| (cmds[i] == RRR) || cmds[i] == RR)
				clean_rotate(&cmds[i], 0, 4, -2);
		}
	}
	free(prev);
	clean_redundance(root, cmds);
}

void	optimize_swap(char *cmds, char id)
{
	int	rev;
	int	count;
	int	i;

	rev = 0;
	count = 0;
	i = -1;
	while (cmds[++i] && count < 3)
	{
		if (count == 1 && ((id == A && cmds[i] == RRA) 
			|| (id == B && cmds[i] == RRB)))
			rev = 1;
		if ((count == 0 && ((id == A && cmds[i] == PB) || (id == B && cmds[i] == PA)))
			|| (count == 1 && ((id == A && (cmds[i] == RA || cmds[i] == RRA))
					  || (id == B && (cmds[i] == RB || cmds[i] == RRB))))
			|| (count == 2 && ((id == A && cmds[i] == PA) || (id == B && cmds[i] == PB))))
				count++;
		else if (cmds[i] != TO_CLEAN)
			count = 10;
	}
	if (count == 3)
		add_best(cmds, id, rev);
}

void	optimize_rot(char *cmds, char cmd, int count_id)
{
    int count_r;
    int i;
    int j;

    // Verifica se o primeiro comando é o esperado
    if (cmds[0] != cmd)
        return;

    count_r = 0;
    i = -1;

    // Conta o número de vezes que o comando `cmd` aparece, ignorando `TO_CLEAN`
    while (cmds[++i] == cmd || cmds[i] == TO_CLEAN)
    {
        if (cmds[i] == cmd)
            count_r++;
    }

    j = 0;

    // Substitui os comandos conforme a contagem e o valor de `count_id`
    while (count_r > count_id / 2 && j != i)
    {
        if (count_r != count_id)
        {
            if (cmd == RA)
                cmds[j++] = RRA;  // Troca RA por RRA
            else if (cmd == RB)
                cmds[j++] = RRB;  // Troca RB por RRB
            else if (cmd == RRA)
                cmds[j++] = RA;   // Troca RRA por RA
            else if (cmd == RRB)
                cmds[j++] = RB;   // Troca RRB por RB
            count_r++;
        }
        else
        {
            cmds[j++] = TO_CLEAN;  // Limpa o comando se count_r igual a count_id
        }
    }
}

// int *count_update(int count[4], int r, int tmp0, int tmp1)
// {
//     if (r > 4)
//     {
//         // Contabiliza rotação normal (RA, RB) e reverse (RRA, RRB)
//         count[0] += (r == RA);   // Se r é RA, incrementa count[0]
//         count[1] += (r == RRA);  // Se r é RRA, incrementa count[1]
//         count[2] += (r == RB);   // Se r é RB, incrementa count[2]
//         count[3] += (r == RRB);  // Se r é RRB, incrementa count[3]
//     }
//     else if (r == -1)
//     {
//         // Ajuste das contagens para as rotações e reverses
//         count[0] = (count[0] - count[1]) * (count[0] > count[1]);
//         count[1] = (count[1] - tmp0) * (count[1] > tmp0);
//         count[2] = (count[2] - count[3]) * (count[2] > count[3]);
//         count[3] = (count[3] - tmp1) * (count[3] > tmp1);
//     }
//     else
//     {
//         // Ajusta os contadores removendo valores conforme tmp0 e tmp1
//         count[0] -= (tmp1 && count[0]);
// 		count[1] -= (tmp0 && count[1]);
// 		count[2] -= (tmp1 && count[2]);
// 		count[3] -= (tmp0 && count[3]);
//     }
//     return (count);
// }
//



int *count_update(int count[4], int r, int tmp0, int tmp1)
{
    // Verifica se r é RA, RB, RRA ou RRB para ajustar as contagens
    if (r == RA)
        count[0]++;
    else if (r == RRA)
        count[1]++;
    else if (r == RB)
        count[2]++;
    else if (r == RRB)
        count[3]++;
    else if (r == -1)  // Ajuste das contagens quando r == -1
    {
        // Ajusta as contagens, garantindo que não fiquem negativas
        if (count[0] > count[1])
            count[0] -= count[1];
        else
            count[0] = 0;

        if (count[1] > tmp0)
            count[1] -= tmp0;
        else
            count[1] = 0;

        if (count[2] > count[3])
            count[2] -= count[3];
        else
            count[2] = 0;

        if (count[3] > tmp1)
            count[3] -= tmp1;
        else
            count[3] = 0;
    }
    else  // Reduz os contadores conforme tmp0 e tmp1
    {
        if (tmp1 && count[0] > 0)
            count[0]--;
        if (tmp0 && count[1] > 0)
            count[1]--;
        if (tmp1 && count[2] > 0)
            count[2]--;
        if (tmp0 && count[3] > 0)
            count[3]--;
    }

    // Log para verificar os valores de count após a atualização
    printf("count[0]: %d, count[1]: %d, count[2]: %d, count[3]: %d\n", count[0], count[1], count[2], count[3]);

    return count;
}
*/

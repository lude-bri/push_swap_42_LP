/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:10:00 by luigi             #+#    #+#             */
/*   Updated: 2024/09/15 18:59:53 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_op(t_ps *root, char *cmds);
static int	parse_cmds(t_ps *root, char *cmds);
static char    *get_next_line_ps(int fd);
static char    *get_left(char *str);
static char    *line_to_clean(char *line);
static char    *fill_line(int fd, char *line);


void	checker(t_ps *root)
{
	char	*line;

	while (1)
	{
		line = get_next_line_ps(0);
		if (!line)
			return ;
		check_op(root, line);
	}
	if (is_sorted(root->a) == 1 && root->b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static char    *get_next_line_ps(int fd)
{
    static char     *line;
    char            *new_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if (!line)
    {
        line = malloc(1);
        line[0] = '\0';
    }
    line = fill_line(fd, line);
    if (!line)
        return NULL;
    new_line = line_to_clean(line);
    line = get_left(line);
    return (new_line);
}

static char    *fill_line(int fd, char *line)
{
    char    *buffer;
    int     bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return NULL;
    bytes_read = 1;
    while (bytes_read != 0 && !ft_strchr(line, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (buffer);
            free (line);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        line = ft_strjoin(line, buffer);
    }
    free(buffer);
    return (line);
}

static char    *line_to_clean(char *line)
{
    char    *new_line;
    int     i;

    i = 0;
    if (!line[i])
        return NULL;
    while(line[i] && line[i] != '\n')
        i++;
    new_line = malloc(sizeof(char) * (i + 2));
    if (!new_line)
        return NULL;
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        new_line[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
    {
        new_line[i] = line[i];
        i++;
    }
    new_line[i] = '\0';
    return (new_line);
}

static char    *get_left(char *line)
{
    char    *rest;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (!line[i])
	{
		free (line);
		return NULL;
	}
    rest = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
    if (!rest)
        return NULL;
    while (line[i])
        rest[j++] = line[i++];
    rest[j] = '\0';
    free (line);
    return (rest);
}
// void	checker(t_ps *root)
// {
// 	// int		result;
// 	char	*line;
//
// 	// result = 1;
// 	// while (result)
// 	// {
// 	// 	// line = get_next_line(0);
// 	// 	// if (!line)
// 	// 	// 	result = 0;
// 	// 	// else
// 	// 	// 	check_op(root, root->cmds);
// 	// }
// 	line = ft_strdup(root->cmds);
// 	if (!line)
// 		return ;
// 	check_op(root, line);
// 	if (is_sorted(root->a))
// 		ft_printf("OK\n");
// 	else
// 		ft_printf("KO\n");
// }



static void	check_op(t_ps *root, char *cmds)
{
	int res;

	if ((cmds == NULL) || (ft_strlen(cmds) == 1)) // Verifica se o comando é inválido
		res = -1;
	else
		res = parse_cmds(root, cmds);
	if (cmds != NULL)
		free(cmds); // Libera a linha lida pelo get_next_line
	if (res == -1)
	{
		free_ab(root);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

// static void	check_op(t_ps *root, char *cmds)
// {
// 	int	result;
//
// 	if ((cmds == NULL) || (ft_strlen(cmds) == 1))
// 		result = -1;
// 	else
// 		result = parse_cmds(root, cmds);
// 	if (cmds != NULL)
// 		free(cmds);
// 	if (result == -1)
// 	{
// 		free_ab(root);
// 		get_next_line(0);
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// }
//

static int	parse_cmds(t_ps *root, char *cmds)
{
	if (ft_strncmp(cmds, "pa\n", 3) == 0)
		do_cmd(root, PA);
	else if (ft_strncmp(cmds, "pb\n", 3) == 0)
		do_cmd(root, PB);
	else if (ft_strncmp(cmds, "sa\n", 3) == 0)
		do_cmd(root, SA);
	else if (ft_strncmp(cmds, "sb\n", 3) == 0)
		do_cmd(root, SB);
	else if (ft_strncmp(cmds, "ss\n", 3) == 0)
		do_cmd(root, SS);
	else if (ft_strncmp(cmds, "ra\n", 3) == 0)
		do_cmd(root, RA);
	else if (ft_strncmp(cmds, "rb\n", 3) == 0)
		do_cmd(root, RB);
	else if (ft_strncmp(cmds, "rr\n", 3) == 0)
		do_cmd(root, RR);
	else if (ft_strncmp(cmds, "rra\n", 4) == 0)
		do_cmd(root, RRA);
	else if (ft_strncmp(cmds, "rrb\n", 4) == 0)
		do_cmd(root, RRB);
	else if (ft_strncmp(cmds, "rrr\n", 4) == 0)
		do_cmd(root, RRR);
	else
		return (-1);
	return (1);
}
//
// static int	parse_cmds(t_ps *root, char *cmds)
// {
// 	if (ft_strncmp(cmds, "pa\n", 3) == 0)
// 		do_cmd(root, PA);
// 	else if (ft_strncmp(cmds, "pb\n", 3) == 0)
// 		do_cmd(root, PB);
// 	else if (ft_strncmp(cmds, "sa\n", 3) == 0)
// 		do_cmd(root, SA);
// 	else if (ft_strncmp(cmds, "sb\n", 3) == 0)
// 		do_cmd(root, SB);
// 	else if (ft_strncmp(cmds, "ss\n", 3) == 0)
// 		do_cmd(root, SS);
// 	else if (ft_strncmp(cmds, "ra\n", 3) == 0)
// 		do_cmd(root, RA);
// 	else if (ft_strncmp(cmds, "rb\n", 3) == 0)
// 		do_cmd(root, RB);
// 	else if (ft_strncmp(cmds, "rr\n", 3) == 0)
// 		do_cmd(root, RR);
// 	else if (ft_strncmp(cmds, "rra\n", 4) == 0)
// 		do_cmd(root, RRA);
// 	else if (ft_strncmp(cmds, "rrb\n", 4) == 0)
// 		do_cmd(root, RRB);
// 	else if (ft_strncmp(cmds, "rrr\n", 4) == 0)
// 		do_cmd(root, RRR);
// 	else
// 		return (-1);
// 	return (1);
// }
//


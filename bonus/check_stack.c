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
static char	*get_next_line_ps(int fd);
static char	*fill_line(int fd, char *raw);
static char	*line_to_clean(char *raw);
static char	*get_rest(char *raw);

void	checker(t_ps *root)
{
	char	*line;
	int		res;

	//line = NULL;
	res = 0;
	while (res == 0)
	{
		line = get_next_line_ps(0);
		if (!line)
			res = 1;
		else
			check_op(root, line);
	}
	if (is_sorted(root->a) == 1 && root->b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}


static char	*get_next_line_ps(int fd)
{
	char			*line;
	static char		*raw_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!raw_line)
	{
		raw_line = malloc(1);
		raw_line[0] = '\0';
	}
	raw_line = fill_line(fd, raw_line);
	if (!raw_line)
		return (NULL);
	line = line_to_clean(raw_line);
	raw_line = get_rest(raw_line);
	return (line);
}

/*2. fill_line */
static char	*fill_line(int fd, char *raw)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (raw)
				return (raw);
			free(raw);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		raw = ft_strjoin(raw, buffer);
		if (ft_strchr(raw, '\n'))
			break ;
	}
	free(buffer);
	return (raw);
}

/*3. line_to_clean */
static char	*line_to_clean(char *raw)
{
	int		i;
	char	*line;

	i = 0;
	if (!*raw)
		return (NULL);
	while (raw[i] != '\0' && raw[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (raw[i] != '\0' && raw[i] != '\n')
	{
		line[i] = raw[i];
		i++;
	}
	if (raw[i] == '\n')
	{
		line[i] = raw[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*4. get_rest */
static char	*get_rest(char *raw)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (raw[i] != '\0' && raw[i] != '\n')
		i++;
	if (!raw[i])
	{
		free(raw);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(raw) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (raw[i])
		rest[j++] = raw[i++];
	free(raw);
	rest[j] = '\0';
	return (rest);
}



static void	check_op(t_ps *root, char *cmds)
{
	int res;

	// if ((cmds == NULL) || (ft_strlen(cmds) == 1)) // Verifica se o comando é inválido
	// 	res = -1;
	// else
	res = parse_cmds(root, cmds);
	if (cmds != NULL)
		free(cmds); // Libera a linha lida pelo get_next_line
	if (res == -1)
	{
		free_ab(root);
		ft_putstr_fd("Error BONUS\n", 2);
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


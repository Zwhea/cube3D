/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/31 17:28:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_file(t_game *g, char *file);
static void	_get_map_size(t_game *g, int fd);
static bool	is_map(char *line);

/*----------------------------------------------------------------------------*/

char	**get_file(t_game *g, char *file)
{
	if (_check_file(g, file) == -1)
	{
		error_switchman(g, bad_file);
		return (NULL);
	}
	return (g->file.split_file);
}

static int	_check_file(t_game *g, char *file)
{
	int		fd;
	char	*line;
	bool	map;

	map = false;
	if (check_extension(file, ".cub") != true)
		return (-1);
	fd = open_file(file);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line) != false)
		{
			map = true;
			_get_map_size(g, fd);
			break ;
		}
		line = get_next_line(fd);
	}
	// if (map == true)
	// 	get_map(g, fd, line);
	return (0);
}

static void	_get_map_size(t_game *g, int fd)
{
	char	*line;

	line = get_next_line(fd);
		printf("%s", line);
	g->map.size_y = 1;
	while (line)
	{
		line = get_next_line(fd);
		g->map.size_y++;
	}
	printf(GREEN"%d\n"END, g->map.size_y);
}

static bool	is_map(char *line)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	if (line[i] == '\n')
		return (false);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != '\n')
		{
			if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E' || line[i] == 'S')
				player++;
			else
				return (false);
		}
		i++;
	}
	if (player > 1)
		return (false);
	return (true);
}
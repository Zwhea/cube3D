/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/19 15:22:52 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_file(t_game *g, char *file);
static void	_pathfinder(t_game *g);

/*----------------------------------------------------------------------------*/

int	parsing(t_game *g, char **av)
{
	if (_check_file(g, av[1]) > 0)
	{
		init_mlx(g);
		_pathfinder(g);
		map_checker(g);
		textures_checker(g);
		color_checker(g);
	}
	else
	{
		error_switchman(g, wrong_file);
		return (1);
	}
	return (0);
}

static int	_check_file(t_game *g, char *file)
{
	if (check_extension(file, ".cub") != true)
		return (-1);
	g->file.fd = open_file(file);
	if (g->file.fd < 0)
		return (-1);
	g->file.file = file;
	return (g->file.fd);
}

static void	_pathfinder(t_game *g)
{
	int		start_map;
	char	*line;

	start_map = 1;
	line = get_next_line(g->file.fd);
	while (line && !(is_map(line)))
	{
		asset_switchman(g, line);
		free(line);
		line = get_next_line(g->file.fd);
		start_map++;
	}
	if (line)
	{
		free(line);
		get_map(g, g->file.fd, start_map);
	}
	else
		error_switchman(g, wrong_map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 15:32:56 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_file(t_game *g, char *file);
static int	_file_property(char *file);

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
	fd = _file_property(file);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line && !(is_map(line)))
	{
		which_asset(g, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		free(line);
		map = true;
		get_map(g, fd);
	}
	return (0);
}

static int	_file_property(char *file)
{
	int	fd;

	fd = -1;
	if (check_extension(file, ".cub") != true)
		return (-1);
	fd = open_file(file);
	if (fd < 0)
		return (-1);
	return (fd);
}

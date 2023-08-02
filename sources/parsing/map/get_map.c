/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:58:49 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 18:40:01 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static size_t	_get_map_size(t_game *g, int fd);

/*----------------------------------------------------------------------------*/

void	get_map(t_game *g, int fd, int start_map)
{
	int		i;
	char	*tmp_line;

	i = 0;
	tmp_line = NULL;
	g->map.map = (char **)ft_calloc(_get_map_size(g, fd) + 1, sizeof(char *));
	fd = open_file(g->file.file);
	while (start_map >= 0)
	{
		free(tmp_line);
		tmp_line = get_next_line(fd);
		start_map--;
	}
	while (tmp_line)
	{
		g->map.map[i] = tmp_line;
		tmp_line = get_next_line(fd);
		// printf("%s", g->map.map[i]);
		i++;
	}
	g->map.map[i] = NULL;
	close(fd);
	free_split(g->map.map, ft_arraylen((void **)g->map.map));
}

static size_t	_get_map_size(t_game *g, int fd)
{
	char	*line;

	line = get_next_line(fd);
	g->map.size.y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		g->map.size.y++;
	}
	if (line)
		free(line);
	close(fd);
	return (g->map.size.y);
}

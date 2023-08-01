/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:58:49 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 15:26:22 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static size_t	_get_map_size(t_game *g, int fd);

/*----------------------------------------------------------------------------*/

void	get_map(t_game *g, int fd)
{
	g->map.map = (char **)ft_calloc(_get_map_size(g, fd), sizeof(char *));
	free(g->map.map);
}

static size_t	_get_map_size(t_game *g, int fd)
{
	char	*line;

	line = get_next_line(fd);
	g->map.size_y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		g->map.size_y++;
	}
	if (line)
		free(line);
	// printf(GREEN"size : %d\n"END, g->map.size_y);
	return (g->map.size_y);
}

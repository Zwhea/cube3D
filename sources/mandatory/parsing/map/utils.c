/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:04:52 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 13:29:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_map(char *s)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	if (ft_isempty(s))
		return (false);
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != ' ' && s[i] != '\n')
		{
			if (s[i] == 'N' || s[i] == 'W' || s[i] == 'E' || s[i] == 'S')
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

size_t	set_map_height(t_game *g, int fd)
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

void	set_map_width(t_game *g, char *line)
{
	if (ft_strlen_char(line, '\n') > g->map.size.x)
		g->map.size.x = ft_strlen_char(line, '\n');
}

void	set_direction(t_game *g, char c)
{
	if (c == north)
	{
		g->player.north = true;
		set_vector_f(&g->player.view, 0, 1);
	}
	else if (c == south)
	{
		g->player.south = true;
		set_vector_f(&g->player.view, 0, -1);
	}
	else if (c == west)
	{
		g->player.west = true;
		set_vector_f(&g->player.view, -1, 0);
	}
	else
	{
		g->player.east = true;
		set_vector_f(&g->player.view, 1, 0);
	}
	g->player.angle_view = get_angle_degree(g);
}

void	check_around(t_game *g, int x, int y)
{
	if (x == 0 || y == 0 || x == g->map.size.y || y == g->map.line_len[x] - 1)
		error_switchman(g, wrong_map);
	if (g->map.line_len[x + 1] <= y || g->map.line_len[x - 1] <= y \
		|| g->map.b_map[x + 1][y] == empty || g->map.b_map[x - 1][y] == empty \
		|| g->map.b_map[x][y + 1] == empty || g->map.b_map[x][y - 1] == empty)
		error_switchman(g, wrong_map);
}

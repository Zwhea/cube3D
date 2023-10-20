/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:24:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/20 13:55:44 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	door_direction(t_game *g, int x, int y)
{
	if (y < g->map.size.y && x < g->map.size.x && g->map.map[y][x] == door)
	{
		if (g->map.map[y - 1][x] == wall && g->map.map[y + 1][x] == wall \
			&& (g->map.map[y][x - 1] != wall || g->map.map[y][x + 1] != wall))
			return (0);
		else if ((g->map.map[y - 1][x] != wall || g->map.map[y + 1][x] != wall) \
			&& g->map.map[y][x - 1] == wall && g->map.map[y][x + 1] == wall)
			return (1);
	}
	return (-1);
}

void	draw_north(t_game *g)
{
	t_vector	north;
	float		tmp;

	set_vector(&north, 0, 0 - g->mini_map.rayon);
	tmp = north.x;
	north.x = ((north.x * cos((-1) * g->player.angle_view - M_PI_2)) \
				- (north.y * sin((-1) * g->player.angle_view - M_PI_2)));
	north.x += g->mini_map.center;
	north.y = ((tmp * sin((-1) * g->player.angle_view - M_PI_2)) \
				+ (north.y * cos((-1) * g->player.angle_view - M_PI_2)));
	north.y += g->mini_map.center;
	draw_circle(g, &north, 12, H_BLACK);
	draw_circle(g, &north, 10, H_WHITE);
	g->mini_map.north = north;
}

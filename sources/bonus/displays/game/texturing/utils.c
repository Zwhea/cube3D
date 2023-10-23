/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:45:38 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 09:47:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_dir_wall(t_game *g, int check)
{
	if (check == 1)
	{
		if (g->ray.check.x < g->player.pos.x)
			g->ray.wall_dir = west;
		else if (g->ray.check.x > g->player.pos.x)
			g->ray.wall_dir = east;
		g->ray.intersection.x = g->ray.ray_len.x - g->ray.ray_unit.x;
		g->ray.intersection.y = g->ray.ray_len.y;
	}
	else
	{
		if (g->ray.check.y < g->player.pos.y)
			g->ray.wall_dir = north;
		else if (g->ray.check.y > g->player.pos.y)
			g->ray.wall_dir = south;
		g->ray.intersection.x = g->ray.ray_len.x;
		g->ray.intersection.y = g->ray.ray_len.y - g->ray.ray_unit.y;
	}
}

unsigned int	get_shade(t_game *game, unsigned int color)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	if (game->ray.dist > 6)
	{
		ratio = 1 - ((game->ray.dist - 6) * 0.1);
		r = (int)(r * ratio);
		g = (int)(g * ratio);
		b = (int)(b * ratio);
	}
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

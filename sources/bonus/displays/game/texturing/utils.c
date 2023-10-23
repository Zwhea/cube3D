/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:49:00 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/23 09:49:01 by aascedu          ###   ########.fr       */
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

unsigned int	get_door_color(t_game *g, t_vector texture, double wall_x)
{
	texture.x = g->textures.walls[north_texture].width * \
	(g->doors[g->id].move - wall_x);
	return (my_mlx_pix_get(&g->sprites.door, texture.x, texture.y));
}

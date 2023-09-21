/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:05:31 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/21 14:22:53 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	raycasting(t_game *g, float angle)
{
	t_vector_f	ray_start;
	t_vector_f	ray_dir;
	t_vector_f	ray_unit;
	t_vector_f	ray_len;
	t_vector	check;
	t_vector	step;
	int			wall;
	int			door;
	double		dist;
	t_vector_f	intersection;

	ray_unit.x = sqrt(1 + pow(tan(angle), 2));
	ray_unit.y = sqrt(1 + pow(1 / tan(angle), 2));
	ray_dir.x = cos(angle);
	ray_dir.y = sin(angle);
	ray_start = g->player.posf;
	check = g->player.pos;
	if (ray_dir.x < 0)
	{
		step.x = -1;
		ray_len.x = (ray_start.x - (float)check.x) * ray_unit.x;
	}
	else
	{
		step.x = 1;
		ray_len.x = ((float)(check.x + 1) - ray_start.x) * ray_unit.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		ray_len.y = (ray_start.y - (float)check.y) * ray_unit.y;
	}
	else
	{
		step.y = 1;
		ray_len.y = ((float)(check.y + 1) - ray_start.y) * ray_unit.y;
	}
	wall = 0;
	door = 0;
	dist = 0;
	while (wall == 0 && door == 0)
	{
		if (ray_len.x < ray_len.y)
		{
			check.x += step.x;
			ray_len.x += ray_unit.x;
			dist = ray_len.x;
		}
		else
		{
			check.y += step.y;
			ray_len.y += ray_unit.y;
			dist = ray_len.y;
		}
		if (g->map.map[check.y][check.x] == '1')
			wall = 1;
		else if (g->map.map[check.y][check.x] == '-')
			door = 1;
	}
	dist -= 1;
	intersection.x = ray_start.x + ray_dir.x * dist;
	intersection.y = ray_start.y + ray_dir.y * dist;
	double	cam_dist;
	cam_dist = (WINDOW_X / 2) / cos(30);
	cam_dist = abs(cam_dist);
	double	wall_ratio;
	wall_ratio = 128 / (dist * cam_dist);
	int	wall_size;
	wall_size = wall_ratio * WINDOW_Y;
	int	over_wall = (WINDOW_Y / 2) - (wall_size / 2);
	int	under_wall = WINDOW_Y / 2 + (wall_size / 2);
	while (g->size.y <= WINDOW_Y - 1 && g->size.y >= 0 && g->size.x <= WINDOW_X - 1 && g->size.x >= 0)
	{
		if (g->size.y >= over_wall && g->size.y <= under_wall)
		{
			if (wall)
				my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
			else if (door)
				my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
		}
		g->size.y++;
	}
}

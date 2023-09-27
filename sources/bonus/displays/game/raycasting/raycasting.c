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
			dist = ray_len.x;
			ray_len.x += ray_unit.x;
		}
		else
		{
			check.y += step.y;
			dist = ray_len.y;
			ray_len.y += ray_unit.y;
		}
		if (g->map.map[check.y][check.x] == '1')
			wall = 1;
		else if (g->map.map[check.y][check.x] == '-')
			door = 1;
	}
	double	cam_dist;
	double	wall_ratio;
	double	wall_size;
	cam_dist = (960) / tan(M_PI / 6);
	wall_ratio = cam_dist / dist;
	// wall_size = wall_ratio * WINDOW_Y;
	if (angle - g->player.angle_view > 0)
		wall_size = wall_ratio * cos(0.5235);
	else
		wall_size = wall_ratio * cos(-0.5235);
	int	top_wall = (540) - (wall_size / 2);
	int	bottom_wall = (540) + (wall_size / 2);
	while (g->size.y <= WINDOW_Y - 1 && g->size.y >= 0 && g->size.x <= WINDOW_X - 1 && g->size.x >= 0)
	{
		if (g->size.y >= top_wall && g->size.y <= bottom_wall)
		{
			if (wall)
				my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
			else if (door)
				my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
		}
		g->size.y++;
	}
}

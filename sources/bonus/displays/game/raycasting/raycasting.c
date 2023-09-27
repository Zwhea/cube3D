/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:05:31 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/26 14:59:11 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_var(t_game *g, float angle)
{

}

void	raycasting(t_game *g, float angle)
{
	g->ray.ray_unit.x = sqrt(1 + pow(tan(angle), 2));
	g->ray.ray_unit.y = sqrt(1 + pow(1 / tan(angle), 2));
	g->ray.ray_dir.x = cos(angle);
	g->ray.ray_dir.y = sin(angle);
	g->ray.ray_start = g->player.posf;
	g->ray.check = g->player.pos;
	if (g->ray.ray_dir.x < 0)
	{
		g->ray.step.x = -1;
		g->ray.ray_len.x = (g->ray.ray_start.x - (float)g->ray.check.x) * g->ray.ray_unit.x;
	}
	else
	{
		g->ray.step.x = 1;
		g->ray.ray_len.x = ((float)(g->ray.check.x + 1) - g->ray.ray_start.x) * g->ray.ray_unit.x;
	}
	if (g->ray.ray_dir.y < 0)
	{
		g->ray.step.y = -1;
		g->ray.ray_len.y = (g->ray.ray_start.y - (float)g->ray.check.y) * g->ray.ray_unit.y;
	}
	else
	{
		g->ray.step.y = 1;
		g->ray.ray_len.y = ((float)(g->ray.check.y + 1) - g->ray.ray_start.y) * g->ray.ray_unit.y;
	}
	g->ray.wall = 0;
	g->ray.door = 0;
	g->ray.dist = 0;
	while (g->ray.wall == 0 && g->ray.door == 0)
	{
		if (g->ray.ray_len.x < g->ray.ray_len.y)
		{
			g->ray.check.x += g->ray.step.x;
			g->ray.dist = g->ray.ray_len.x;
			g->ray.ray_len.x += g->ray.ray_unit.x;
		}
		else
		{
			g->ray.check.y += g->ray.step.y;
			g->ray.dist = g->ray.ray_len.y;
			g->ray.ray_len.y += g->ray.ray_unit.y;
		}
		if (g->map.map[g->ray.check.y][g->ray.check.x] == '1')
			g->ray.wall = 1;
		else if (g->map.map[g->ray.check.y][g->ray.check.x] == '-')
			g->ray.door = 1;
	}
	g->ray.dist *= cos(angle - g->player.angle_view);
	double	cam_dist;
	double	wall_ratio;
	double	wall_size;
	cam_dist = (960) / tan(M_PI / 6);
	wall_ratio = cam_dist / g->ray.dist;
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
			if (g->ray.wall)
				my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
			else if (g->ray.door)
				my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
		}
		g->size.y++;
	}
}

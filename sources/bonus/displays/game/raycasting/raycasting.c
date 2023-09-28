/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:05:31 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/28 13:33:06 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_var(t_game *g, float angle)
{
	ft_bzero((void *)&g->ray, sizeof(t_raycast));
	g->ray.ray_unit.x = sqrt(1 + pow(tan(angle), 2));
	g->ray.ray_unit.y = sqrt(1 + pow(1 / tan(angle), 2));
	g->ray.ray_dir.x = cos(angle);
	g->ray.ray_dir.y = sin(angle);
	g->ray.ray_start = g->player.posf;
	g->ray.check = g->player.pos;
	g->ray.cam_dist = (960) / tan(M_PI / 6);
}

void	init_ray(t_game *g)
{
	if (g->ray.ray_dir.x < 0)
	{
		g->ray.step.x = -1;
		g->ray.ray_len.x = (g->ray.ray_start.x - (float)g->ray.check.x)
			* g->ray.ray_unit.x;
	}
	else
	{
		g->ray.step.x = 1;
		g->ray.ray_len.x = ((float)(g->ray.check.x + 1) - g->ray.ray_start.x)
			* g->ray.ray_unit.x;
	}
	if (g->ray.ray_dir.y < 0)
	{
		g->ray.step.y = -1;
		g->ray.ray_len.y = (g->ray.ray_start.y - (float)g->ray.check.y)
			* g->ray.ray_unit.y;
	}
	else
	{
		g->ray.step.y = 1;
		g->ray.ray_len.y = ((float)(g->ray.check.y + 1) - g->ray.ray_start.y)
			* g->ray.ray_unit.y;
	}
}

void	find_dir_wall(t_game *g, int check)
{
	if (check == 1) // Vertical
	{
		if (g->ray.check.x < g->player.pos.x)
			g->ray.wall_dir = 1;
		else if (g->ray.check.x > g->player.pos.x)
			g->ray.wall_dir = 3;
	}
	else
	{
		if (g->ray.check.y < g->player.pos.y)
			g->ray.wall_dir = 2;
		else if (g->ray.check.y > g->player.pos.y)
			g->ray.wall_dir = 4;
	}
}

void	find_dist(t_game *g, float angle)
{
	while (g->ray.wall == 0 && g->ray.door == 0)
	{
		if (g->ray.ray_len.x < g->ray.ray_len.y)
		{
			g->ray.check.x += g->ray.step.x;
			g->ray.dist = g->ray.ray_len.x;
			g->ray.ray_len.x += g->ray.ray_unit.x;
			find_dir_wall(g, 1);
		}
		else
		{
			g->ray.check.y += g->ray.step.y;
			g->ray.dist = g->ray.ray_len.y;
			g->ray.ray_len.y += g->ray.ray_unit.y;
			find_dir_wall(g, 2);
		}
		if (g->map.map[g->ray.check.y][g->ray.check.x] == '1')
			g->ray.wall = 1;
		else if (g->map.map[g->ray.check.y][g->ray.check.x] == '-')
			g->ray.door = 1;
	}
	g->ray.dist *= cos(angle - g->player.angle_view);
}

void	draw_textures(t_game *g)
{
	if (g->ray.wall && g->ray.wall_dir == 1)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
	else if (g->ray.wall && g->ray.wall_dir == 2)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_BLUE);
	else if (g->ray.wall && g->ray.wall_dir == 3)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_WHITE);
	else if (g->ray.wall && g->ray.wall_dir == 4)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_RED);
	else if (g->ray.door)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
}

void	raycasting(t_game *g, float angle)
{
	init_var(g, angle);
	init_ray(g);
	find_dist(g, angle);
	g->ray.wall_ratio = g->ray.cam_dist / g->ray.dist;
	if (angle - g->player.angle_view > 0)
		g->ray.wall_size = g->ray.wall_ratio * cos(0.5235);
	else
		g->ray.wall_size = g->ray.wall_ratio * cos(-0.5235);
	g->ray.top_wall = (540) - (g->ray.wall_size / 2);
	g->ray.bottom_wall = (540) + (g->ray.wall_size / 2);
	while (g->size.y <= WINDOW_Y - 1 && g->size.y >= 0
		&& g->size.x <= WINDOW_X - 1 && g->size.x >= 0)
	{
		if (g->size.y >= g->ray.top_wall && g->size.y <= g->ray.bottom_wall)
		{
			draw_textures(g);
		}
		g->size.y++;
	}
}

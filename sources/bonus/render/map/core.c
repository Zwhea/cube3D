/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:47 by aascedu           #+#    #+#             */
/*   Updated: 2023/08/23 08:46:48 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	down_left_corner(t_game *g)
{
	int	y;
	int	x;

	y = g->player.pos.y;
	while (g->map.map[y] && y < g->player.pos.y + 5)
	{
		x = g->player.pos.x;
		while (x >= 0 && g->map.map[y][x] && x > g->player.pos.x - 5)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, ((4 + x - g->player.pos.x)) * 30, (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, ((4 + x - g->player.pos.x)) * 30, (4 + y - g->player.pos.y) * 30, H_WHITE);
			x--;
		}
		y++;
	}
}

void	down_right_corner(t_game *g)
{
	int	y;
	int	x;

	y = g->player.pos.y;
	while (g->map.map[y] && y < g->player.pos.y + 5)
	{
		x = g->player.pos.x;
		while (g->map.map[y][x] && x < g->player.pos.x + 5)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, (4 + x - g->player.pos.x) * 30, (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, (4 + x - g->player.pos.x) * 30, (4 + y - g->player.pos.y) * 30, H_WHITE);
			x++;
		}
		y++;
	}
}

void	up_right_corner(t_game *g)
{
	int	y;
	int	x;

	y = g->player.pos.y;
	while (y >= 0 && g->map.map[y] && y > g->player.pos.y - 5)
	{
		x = g->player.pos.x;
		while (g->map.map[y][x] && x < g->player.pos.x + 5)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, (4 + x - g->player.pos.x) * 30, (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, (4 + x - g->player.pos.x) * 30, (4 + y - g->player.pos.y) * 30, H_WHITE);
			x++;
		}
		y--;
	}
}

void	up_left_corner(t_game *g)
{
	int	y;
	int	x;

	y = g->player.pos.y;
	while (y >= 0 && g->map.map[y] && y > g->player.pos.y - 5)
	{
		x = g->player.pos.x;
		while (x >= 0 && g->map.map[y][x] && x > g->player.pos.x - 5)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, ((4 + x - g->player.pos.x)) * 30, (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, ((4 + x - g->player.pos.x)) * 30, (4 + y - g->player.pos.y) * 30, H_WHITE);
			x--;
		}
		y--;
	}
}

void	init_map(t_game *g)
{
	draw_square(g, 120, 120, H_RED);
	down_right_corner(g);
	down_left_corner(g);
	up_right_corner(g);
	up_left_corner(g);
}

void	map_render(t_game *g)
{
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	init_map(g);
	draw_frame(g, MINI_MAP_X, MINI_MAP_Y, H_RED);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

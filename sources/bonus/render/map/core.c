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
				draw_square(g, 30 + ((4 + x - g->player.pos.x)) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, 30 + ((4 + x - g->player.pos.x)) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
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
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
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
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space)
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
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
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space || g->map.map[y][x] == south || g->map.map[y][x] == north)
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, 30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
			x--;
		}
		y--;
	}
}

void	draw_player_square_map(t_game *g, int r)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	while (pos_x <= MINI_MAP_X)
	{
		pos_y = 0;
		while (pos_y <= MINI_MAP_Y)
		{
			if (pow(r, 2) ==  36450 + pow(pos_x, 2) + pow(pos_y, 2) - (270 * pos_x) - (270 * pos_y))
				my_mlx_pixel_put(&g->draw, pos_x, pos_y, H_RED);
			pos_y = pos_y + 1;
		}
		pos_x = pos_x + 1;
	}
}

void	init_map(t_game *g)
{
	down_right_corner(g);
	down_left_corner(g);
	up_right_corner(g);
	up_left_corner(g);
	draw_player_map_square(g, 161, 161, H_RED);
}

void	map_render(t_game *g)
{
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	fill_background(g, WINDOW_X, WINDOW_Y, H_GREEN);
	init_map(g);
	// draw_frame(g, MINI_MAP_X + 30, MINI_MAP_Y + 30, H_BLACK);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

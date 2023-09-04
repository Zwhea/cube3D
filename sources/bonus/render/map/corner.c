/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:41:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/01 12:30:34 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	down_left_corner(t_game *g)
{
	int	y;
	int	x;

	y = g->player.pos.y;
	while (g->map.map[y] && y < g->player.pos.y + 6)
	{
		x = g->player.pos.x;
		while (x >= 0 && g->map.map[y][x] && x > g->player.pos.x - 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_BLACK);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south || \
				g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_WHITE);
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
	while (g->map.map[y] && y < g->player.pos.y + 6)
	{
		x = g->player.pos.x;
		while (g->map.map[y][x] && x < g->player.pos.x + 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_BLACK);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_WHITE);
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
	while (y >= 0 && g->map.map[y] && y > g->player.pos.y - 6)
	{
		x = g->player.pos.x;
		while (g->map.map[y][x] && x < g->player.pos.x + 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_BLACK);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_WHITE);
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
	while (y >= 0 && g->map.map[y] && y > g->player.pos.y - 6)
	{
		x = g->player.pos.x;
		while (x >= 0 && g->map.map[y][x] && x > g->player.pos.x - 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_BLACK);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_WHITE);
			x--;
		}
		y--;
	}
}

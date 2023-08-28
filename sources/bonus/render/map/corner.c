/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:41:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/08/28 07:41:25 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

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
				draw_square(g, 30 + ((4 + x - g->player.pos.x)) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space || g->map.map[y][x] == south || \
				g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 30 + ((4 + x - g->player.pos.x)) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
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
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
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
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
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
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_GREY);
			if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east)
				draw_square(g, 30 + (4 + x - g->player.pos.x) * 30, \
				30 + (4 + y - g->player.pos.y) * 30, H_WHITE);
			x--;
		}
		y--;
	}
}

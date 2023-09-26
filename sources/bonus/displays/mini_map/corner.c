/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:41:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/26 14:57:31 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_draw_door(t_game *g, int x, int y);

/*----------------------------------------------------------------------------*/

void	down_left_corner(t_game *g)
{
	int	y;
	int	x;

	y = g->player.pos.y;
	while (g->map.map[y] && y < g->player.pos.y + 6)
	{
		x = g->player.pos.x;
		while (x < g->map.line_len[y] && x >= 0 && g->map.map[y][x] \
				&& x > g->player.pos.x - 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				_draw_door(g, x, y);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south || \
				g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east || g->map.map[y][x] == o_door)
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
		while (x < g->map.line_len[y] && g->map.map[y][x] \
			&& x < g->player.pos.x + 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
					45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				_draw_door(g, x, y);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east || g->map.map[y][x] == o_door)
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
		while (x < g->map.line_len[y] && g->map.map[y][x] \
			&& x < g->player.pos.x + 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				_draw_door(g, x, y);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east || g->map.map[y][x] == o_door)
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
		while (x < g->map.line_len[y] && x >= 0 && g->map.map[y][x] \
			&& x > g->player.pos.x - 6)
		{
			if (g->map.map[y][x] == wall)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_GREY);
			else if (g->map.map[y][x] == door)
				_draw_door(g, x, y);
			else if (g->map.map[y][x] == space || g->map.map[y][x] == south \
				|| g->map.map[y][x] == north || g->map.map[y][x] == west \
				|| g->map.map[y][x] == east || g->map.map[y][x] == o_door)
				draw_square(g, 45 + (4 + x - g->player.posf.x) * 30, \
				45 + (4 + y - g->player.posf.y) * 30, H_WHITE);
			x--;
		}
		y--;
	}
}

static void	_draw_door(t_game *g, int x, int y)
{
	if (door_direction(g, x, y) != 1)
		draw_v_rectangle(g, 45 + (4 + x - g->player.posf.x) * 30, \
			45 + (4 + y - g->player.posf.y) * 30, H_BLACK);
	if (door_direction(g, x, y) != 0)
		draw_h_rectangle(g, 45 + (4 + x - g->player.posf.x) * 30, \
			45 + (4 + y - g->player.posf.y) * 30, H_BLACK);
}

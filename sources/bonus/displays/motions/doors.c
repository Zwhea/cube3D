/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:39:28 by twang             #+#    #+#             */
/*   Updated: 2023/09/21 09:43:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int		_check_direction(double angle);
static void		_check_door(t_game *g, int y, int x);

/*----------------------------------------------------------------------------*/

void	init_ray_door(t_game *g)
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

void	find_dist_door(t_game *g)
{
	while (g->ray.door == 0 && g->ray.dist < 3)
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
		if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 && g->map.map[g->ray.check.y] && g->ray.check.x < g->map.line_len[g->ray.check.y] && g->map.map[g->ray.check.y][g->ray.check.x] == '-')
		{
			g->map.map[g->ray.check.y][g->ray.check.x] = '+';
			g->ray.door = 1;
		}
		else if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 && g->map.map[g->ray.check.y] && g->ray.check.x < g->map.line_len[g->ray.check.y] && g->map.map[g->ray.check.y][g->ray.check.x] == '+')
		{
			g->map.map[g->ray.check.y][g->ray.check.x] = '-';
			g->ray.door = 1;
		}
	}
}

void	raycasting_door(t_game *g, double angle)
{
	g->ray.ray_unit.x = sqrt(1 + pow(tan(angle), 2));
	g->ray.ray_unit.y = sqrt(1 + pow(1 / tan(angle), 2));
	g->ray.ray_dir.x = cos(angle);
	g->ray.ray_dir.y = sin(angle);
	g->ray.ray_start = g->player.posf;
	g->ray.check = g->player.pos;
	g->ray.door = 0;
	g->ray.dist = 0;
	init_ray_door(g);
	find_dist_door(g);
	game_display(g);
}

int	open_door(t_game *g)
{
	raycasting_door(g, g->player.angle_view);
	// if (g->ray.door == 1 && g->ray.dist < 2)
	// {
	// 	if (g->map.map[g->ray.check.y][g->ray.check.x] == door)
	// 	{
	// 		g->map.map[g->ray.check.y][g->ray.check.x] = o_door;
	// 		game_display(g);
	// 	}
	// }
	// else if (g->ray.door == 2 && g->ray.dist < 2)
	// {
	// 	if (g->map.map[g->ray.check.y][g->ray.check.x] == o_door)
	// 	{
	// 		g->map.map[g->ray.check.y][g->ray.check.x] = door;
	// 		game_display(g);
	// 	}
	// }
	// if (_check_direction(g->player.angle_view) == 0)
	// 	_check_door(g, g->player.pos.y - 1, g->player.pos.x);
	// if (_check_direction(g->player.angle_view) == 1)
	// 	_check_door(g, g->player.pos.y + 1, g->player.pos.x);
	// if (_check_direction(g->player.angle_view) == 2)
	// 	_check_door(g, g->player.pos.y, g->player.pos.x - 1);
	// if (_check_direction(g->player.angle_view) == 3)
	// 	_check_door(g, g->player.pos.y, g->player.pos.x + 1);
	return (0);
}

static int	_check_direction(double angle)
{
	double	pov;

	pov = remainder(angle, (2 * M_PI));
	if ((pov > 5 * M_PI / 4 && pov < 7 * M_PI / 4) \
			|| (pov > -3 * M_PI / 4 && pov < -M_PI_4))
		return (0);
	if ((pov > M_PI_4 && pov < 3 * M_PI / 4) \
			|| (pov > -7 * M_PI / 4 && pov < -5 * M_PI / 4))
		return (1);
	if ((pov > 3 * M_PI / 4 && pov < 5 * M_PI / 4) \
			|| (pov > -5 * M_PI / 4 && pov < -3 * M_PI / 4))
		return (2);
	if ((pov > -M_PI_4 && pov < M_PI_4) \
			|| (pov > -7 * M_PI / 4 && pov < -2 * M_PI))
		return (3);
	return (-1);
}

static void	_check_door(t_game *g, int y, int x)
{
	if (g->map.map[y][x] == door)
	{
		g->map.map[y][x] = o_door;
		game_display(g);
	}
	else if (g->map.map[y][x] == o_door)
	{
		g->map.map[y][x] = door;
		game_display(g);
	}
}

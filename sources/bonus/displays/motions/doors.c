/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:39:28 by twang             #+#    #+#             */
/*   Updated: 2023/10/17 12:52:35 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_raycasting(t_game *g);
static void	_init_ray_door(t_game *g);
static void	_raycasting_door(t_game *g);
static int	_check_door(t_game *g);

/*----------------------------------------------------------------------------*/

int	open_door(t_game *g)
{
	g->sprites.animation = true;
	return (0);
}

void	ray_door(t_game *g)
{
	_init_raycasting(g);
	_init_ray_door(g);
	_raycasting_door(g);
}

static void	_init_raycasting(t_game *g)
{
	g->door.ray_unit.x = sqrt(1 + pow(tan(g->player.angle_view), 2));
	g->door.ray_unit.y = sqrt(1 + pow(1 / tan(g->player.angle_view), 2));
	g->door.ray_dir.x = cos(g->player.angle_view);
	g->door.ray_dir.y = sin(g->player.angle_view);
	g->door.ray_start = g->player.posf;
	g->door.check = g->player.pos;
	g->door.door = 0;
	g->door.dist = 0;
}

static void	_init_ray_door(t_game *g)
{
	if (g->door.ray_dir.x < 0)
	{
		g->door.step.x = -1;
		g->door.ray_len.x = (g->door.ray_start.x - (float)g->door.check.x)
			* g->door.ray_unit.x;
	}
	else
	{
		g->door.step.x = 1;
		g->door.ray_len.x = ((float)(g->door.check.x + 1) - g->door.ray_start.x)
			* g->door.ray_unit.x;
	}
	if (g->door.ray_dir.y < 0)
	{
		g->door.step.y = -1;
		g->door.ray_len.y = (g->door.ray_start.y - (float)g->door.check.y)
			* g->door.ray_unit.y;
	}
	else
	{
		g->door.step.y = 1;
		g->door.ray_len.y = ((float)(g->door.check.y + 1) - g->door.ray_start.y)
			* g->door.ray_unit.y;
	}
}

static void	_raycasting_door(t_game *g)
{
	while (g->door.dist < 3)
	{
		if (g->door.ray_len.x < g->door.ray_len.y)
		{
			g->door.check.x += g->door.step.x;
			g->door.dist = g->door.ray_len.x;
			g->door.ray_len.x += g->door.ray_unit.x;
		}
		else
		{
			g->door.check.y += g->door.step.y;
			g->door.dist = g->door.ray_len.y;
			g->door.ray_len.y += g->door.ray_unit.y;
		}
		if (_check_door(g))
		{
			break ;
		}
	}
}

static int	_check_door(t_game *g)
{
	if (g->door.dist < 3 && g->door.check.x >= 0 && g->door.check.y >= 0 \
			&& g->map.map[g->door.check.y] \
			&& g->door.check.x < g->map.line_len[g->door.check.y] \
			&& g->map.map[g->door.check.y][g->door.check.x] == door)
	{
		return (1);
	}
	else if (g->door.dist < 3 && g->door.check.x >= 0 && g->door.check.y >= 0 \
			&& g->map.map[g->door.check.y] \
			&& g->door.check.x < g->map.line_len[g->door.check.y] \
			&& g->map.map[g->door.check.y][g->door.check.x] == o_door)
	{
		return (1);
	}
	return (0);
}

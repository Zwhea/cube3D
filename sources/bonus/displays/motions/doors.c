/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:39:28 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 14:36:21 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_ray_door(t_game *g);
static int	_raycasting_door(t_game *g);
static int	_check_door(t_game *g);

/*----------------------------------------------------------------------------*/

int	open_door(t_game *g)
{
	int	id;

	id = ray_door(g);
	if (id != -1)
		g->sprites.animation = true;
	return (0);
}

int	ray_door(t_game *g)
{
	int	id;

	g->door.ray_unit.x = sqrt(1 + pow(tan(g->player.angle_view), 2));
	g->door.ray_unit.y = sqrt(1 + pow(1 / tan(g->player.angle_view), 2));
	g->door.ray_dir.x = cos(g->player.angle_view);
	g->door.ray_dir.y = sin(g->player.angle_view);
	g->door.ray_start = g->player.posf;
	g->door.check = g->player.pos;
	g->door.door = 0;
	g->door.dist = 0;
	g->door.wall = 0;
	_init_ray_door(g);
	id = _raycasting_door(g);
	return (id);
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

static int	_raycasting_door(t_game *g)
{
	int	id;

	while (g->door.dist < 3 && g->door.wall == 0)
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
		id = _check_door(g);
		if (id != -1)
			return (id);
		if (g->map.map[g->door.check.y][g->door.check.x] == wall)
			g->door.wall = 1;
	}
	return (-1);
}

static int	_check_door(t_game *g)
{
	int	id;

	if (g->door.check.x >= 0 && g->door.check.y >= 0 \
			&& g->map.map[g->door.check.y] \
			&& g->door.check.x < g->map.line_len[g->door.check.y] \
			&& (g->map.map[g->door.check.y][g->door.check.x] == door \
			|| g->map.map[g->door.check.y][g->door.check.x] == o_door))
	{
		id = get_id(g, g->door.check.x, g->door.check.y);
		g->id = id;
		if (id == -1)
			return (-1);
		if (g->doors[id].status == neutral && g->doors[id].move < 0.01)
			g->doors[id].status = closing;
		else if (g->doors[id].status == neutral && g->doors[id].move > 0.99)
			g->doors[id].status = opening;
		return (id);
	}
	return (-1);
}

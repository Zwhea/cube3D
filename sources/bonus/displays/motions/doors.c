/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:39:28 by twang             #+#    #+#             */
/*   Updated: 2023/10/12 14:49:13 by twang            ###   ########.fr       */
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
	_init_raycasting(g);
	_init_ray_door(g);
	_raycasting_door(g);
	return (0);
}

static void	_init_raycasting(t_game *g)
{
	g->ray.ray_unit.x = sqrt(1 + pow(tan(g->player.angle_view), 2));
	g->ray.ray_unit.y = sqrt(1 + pow(1 / tan(g->player.angle_view), 2));
	g->ray.ray_dir.x = cos(g->player.angle_view);
	g->ray.ray_dir.y = sin(g->player.angle_view);
	g->ray.ray_start = g->player.posf;
	g->ray.check = g->player.pos;
	g->ray.door = 0;
	g->ray.dist = 0;
}

static void	_init_ray_door(t_game *g)
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

static void	_raycasting_door(t_game *g)
{
	while (g->ray.dist < 3)
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
		if (_check_door(g))
		{
			g->sprites.animation = true;
			break ;
		}
	}
}

static int	_check_door(t_game *g)
{
	if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
			&& g->map.map[g->ray.check.y] \
			&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
			&& g->map.map[g->ray.check.y][g->ray.check.x] == door)
	{
		g->sprites.is_open = false;
		return (1);
	}
	else if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
			&& g->map.map[g->ray.check.y] \
			&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
			&& g->map.map[g->ray.check.y][g->ray.check.x] == o_door)
	{
		g->sprites.is_open = true;
		return (1);
	}
	return (0);
}

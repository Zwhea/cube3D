/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:17:39 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 13:10:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_depth_door(t_game *g, int id, double inter, double angle);

/*----------------------------------------------------------------------------*/

int	dstate(t_game *g, int x, int y, float angle)
{
	int		id;
	double	inter;

	id = get_id(g, y, x);
	if (g->ray.wall_dir == east || g->ray.wall_dir == west)
		inter = g->ray.dist * g->ray.ray_dir.y + g->player.posf.y;
	else
		inter = g->ray.dist * g->ray.ray_dir.x + g->player.posf.x;
	inter = inter - floor(inter);
	if ((g->ray.wall_dir == north || g->ray.wall_dir == east) && \
			inter <= g->doors[id].move && g->doors[id].status != neutral)
		return (1);
	else if ((g->ray.wall_dir == south || g->ray.wall_dir == west) \
			&& inter >= 1 - g->doors[id].move && g->doors[id].status != neutral)
		return (1);
	else if ((g->ray.wall_dir == west || g->ray.wall_dir == north \
					|| g->ray.wall_dir == east || g->ray.wall_dir == south) \
					&& g->doors[id].status == neutral \
					&& g->map.map[g->ray.check.y][g->ray.check.x] == '-')
		return (1);
	else if (g->doors[id].status != neutral)
		if (_depth_door(g, id, inter, angle))
			return (1);
	return (0);
}

static int	_depth_door(t_game *g, int id, double inter, double angle)
{
	t_vector_f	f;

	f.x = 0;
	f.y = 0;
	if (angle > 2 * M_PI)
	{
		f.x = 1 - g->doors[id].move - inter;
		if (g->ray.wall_dir != south)
			return (0);
		f.y = f.x * tanf(M_PI_2 - ((M_PI_2) - angle));
	}
	if (angle > (3 * M_PI_2))
	{
		f.x = inter - g->doors[id].move;
		if (g->ray.wall_dir != east)
			return (0);
		f.y = f.x * tanf(M_PI_2 - ((2 * M_PI) - angle));
	}
	else if (angle > (M_PI))
	{
		f.x = inter - (g->doors[id].move);
		if (g->ray.wall_dir != north)
			return (0);
		f.y = f.x * tanf(M_PI_2 - ((3 * M_PI_2) - angle));
	}
	else if (angle > (M_PI_2))
	{
		f.x = 1 - g->doors[id].move - inter;
		if (g->ray.wall_dir != west)
			return (0);
		f.y = f.x * tanf(angle - M_PI_2);
	}
	else
	{
		f.x = 1 - g->doors[id].move - inter;
		if (g->ray.wall_dir != south)
			return (0);
		f.y = f.x * tanf(M_PI_2 - ((M_PI_2) - angle));
	}
	if (f.y > 1)
		return (0);
	if (g->ray.ray_len.x < g->ray.ray_len.y)
		g->ray.dist += sqrt((f.x * f.x) + (f.y * f.y));
	else
		g->ray.dist += sqrt((f.x * f.x) + (f.y * f.y));
	g->ray.wall_dir = side;
	return (1);
}

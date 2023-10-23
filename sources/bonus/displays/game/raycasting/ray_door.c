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
static int	_which_angle(t_game *g, int id, double inter, double angle);

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
	if (!_which_angle(g, id, inter, angle))
		return (0);
	if (g->ray.f.y > 1)
		return (0);
	if (g->ray.ray_len.x < g->ray.ray_len.y)
		g->ray.dist += sqrt((g->ray.f.x * g->ray.f.x) \
		+ (g->ray.f.y * g->ray.f.y));
	else
		g->ray.dist += sqrt((g->ray.f.x * g->ray.f.x) \
		+ (g->ray.f.y * g->ray.f.y));
	g->ray.side = 1;
	return (1);
}

static int	_which_angle(t_game *g, int id, double inter, double angle)
{
	if (angle > 2 * M_PI)
	{
		if (!get_south(g, id, inter, angle))
			return (0);
	}
	else if (angle > (3 * M_PI_2))
	{
		if (!get_east(g, id, inter, angle))
			return (0);
	}
	else if (angle > (M_PI))
	{
		if (!get_north(g, id, inter, angle))
			return (0);
	}
	else if (angle > (M_PI_2))
	{
		if (!get_west(g, id, inter, angle))
			return (0);
	}
	else
		if (!get_south(g, id, inter, angle))
			return (0);
	return (1);
}

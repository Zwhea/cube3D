/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:17:39 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 09:18:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	dstate(t_game *g, int x, int y)
{
	int		id;
	double	inter;

	id = get_id(g, y, x);
	if (g->ray.wall_dir == east || g->ray.wall_dir == west)
		inter = g->ray.dist * g->ray.ray_dir.y + g->player.posf.y;
	else
		inter = g->ray.dist * g->ray.ray_dir.x + g->player.posf.x;
	inter = inter - floor(inter);
	if ((g->ray.wall_dir == west || g->ray.wall_dir == north) && \
			inter <= g->doors[id].move && g->doors[id].status != neutral)
		return (1);
	else if ((g->ray.wall_dir == east || g->ray.wall_dir == south) \
			&& inter <= g->doors[id].move && g->doors[id].status != neutral)
		return (1);
	else if ((g->ray.wall_dir == west || g->ray.wall_dir == north \
		|| g->ray.wall_dir == east || g->ray.wall_dir == south) \
		&& g->doors[id].status == neutral \
		&& g->map.map[g->ray.check.y][g->ray.check.x] == '-')
		return (1);
	return (0);
}


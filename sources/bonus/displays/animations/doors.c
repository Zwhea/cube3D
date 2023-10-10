/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/10 11:49:02 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	door_animations(t_game *g, int door_state)
{
	(void)door_state;
	int	i;

	i = -1;
	while (++i < 300000)
	{
		if (i < 100000 && g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
			&& g->map.map[g->ray.check.y] \
			&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
			&& g->map.map[g->ray.check.y][g->ray.check.x] == door)
		{
			g->map.map[g->ray.check.y][g->ray.check.x] = o_door;
			puts("ouvert");
		}
		else if (i < 200000 && g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
			&& g->map.map[g->ray.check.y] \
			&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
			&& g->map.map[g->ray.check.y][g->ray.check.x] == o_door)
		{
			g->map.map[g->ray.check.y][g->ray.check.x] = door;
			puts("ferme");
		}
		else if (i < 300000 && g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
			&& g->map.map[g->ray.check.y] \
			&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
			&& g->map.map[g->ray.check.y][g->ray.check.x] == door)
		{
			g->map.map[g->ray.check.y][g->ray.check.x] = o_door;
			puts("ouvert");
		}
	}
}

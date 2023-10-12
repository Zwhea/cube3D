/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/12 10:39:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	door_animations(t_game *g, int door_state)
{
	(void)door_state;
	long long int	i;

	i = -1;
	if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
		&& g->map.map[g->ray.check.y] \
		&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
		&& g->map.map[g->ray.check.y][g->ray.check.x] == door)
	{
		while (++i < 10000)
		{
				g->map.map[g->ray.check.y][g->ray.check.x] = o_door;
				puts("ouvert");
		}
	}
	if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
		&& g->map.map[g->ray.check.y] \
		&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
		&& g->map.map[g->ray.check.y][g->ray.check.x] == o_door)
	{
		while (++i < 20000)
		{
				g->map.map[g->ray.check.y][g->ray.check.x] = door;
				puts("ferme");
		}
	}
	if (g->ray.dist < 3 && g->ray.check.x >= 0 && g->ray.check.y >= 0 \
		&& g->map.map[g->ray.check.y] \
		&& g->ray.check.x < g->map.line_len[g->ray.check.y] \
		&& g->map.map[g->ray.check.y][g->ray.check.x] == door)
	{
		while (++i < 30000)
		{
			g->map.map[g->ray.check.y][g->ray.check.x] = o_door;
			puts("ouvert");
		}
	}
	puts("n'importe quoi");
}

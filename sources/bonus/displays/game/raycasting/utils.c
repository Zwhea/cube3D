/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:09:29 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/23 17:09:31 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_south(t_game *g, int id, double inter, double angle)
{
	g->ray.f.x = 1 - g->doors[id].move - inter;
	if (g->ray.wall_dir != south)
		return (0);
	g->ray.f.y = g->ray.f.x * tanf(M_PI_2 - ((M_PI_2) - angle));
	return (1);
}

int	get_north(t_game *g, int id, double inter, double angle)
{
	g->ray.f.x = inter - (g->doors[id].move);
	if (g->ray.wall_dir != north)
		return (0);
	g->ray.f.y = g->ray.f.x * tanf(M_PI_2 - ((3 * M_PI_2) - angle));
	return (1);
}

int	get_west(t_game *g, int id, double inter, double angle)
{
	g->ray.f.x = 1 - g->doors[id].move - inter;
	if (g->ray.wall_dir != west)
		return (0);
	g->ray.f.y = g->ray.f.x * tanf(angle - M_PI_2);
	return (1);
}

int	get_east(t_game *g, int id, double inter, double angle)
{
	g->ray.f.x = inter - g->doors[id].move;
	if (g->ray.wall_dir != east)
		return (0);
	g->ray.f.y = g->ray.f.x * tanf(M_PI_2 - ((2 * M_PI) - angle));
	return (1);
}

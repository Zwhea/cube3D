/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_movable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:00:07 by twang             #+#    #+#             */
/*   Updated: 2023/09/26 14:54:46 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	check_w_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	if (sin(g->player.angle_view) < 0)
		dist_y = floor(g->player.posf.y + 0.1 * sin(g->player.angle_view));
	else
		dist_y = ceil(g->player.posf.y + 0.1 * sin(g->player.angle_view) - 1);
	if (cos(g->player.angle_view) < 0)
		dist_x = floor(g->player.posf.x + 0.1 * cos(g->player.angle_view));
	else
		dist_x = ceil(g->player.posf.x + 0.1 * cos(g->player.angle_view) - 1);
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] \
			&& (g->map.map[dist_y][dist_x] != wall))
		return (0);
	return (1);
}

int	check_s_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	if (sin(g->player.angle_view) < 0)
		dist_x = floor(g->player.posf.x - 0.1 * cos(g->player.angle_view));
	else
		dist_x = ceil(g->player.posf.x - 0.1 * cos(g->player.angle_view) - 1);
	if (cos(g->player.angle_view) > 0)
		dist_y = floor(g->player.posf.y - 0.1 * sin(g->player.angle_view));
	else
		dist_y = ceil(g->player.posf.y - 0.1 * sin(g->player.angle_view) - 1);
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] \
			&& (g->map.map[dist_y][dist_x] != wall))
		return (0);
	return (1);
}

int	check_a_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	if (sin(g->player.angle_view) < 0)
		dist_x = floor(g->player.posf.x + 0.1 * sin(g->player.angle_view));
	else
		dist_x = ceil(g->player.posf.x + 0.1 * sin(g->player.angle_view) - 1);
	if (cos(g->player.angle_view) > 0)
		dist_y = floor(g->player.posf.y - 0.1 * cos(g->player.angle_view));
	else
		dist_y = ceil(g->player.posf.y - 0.1 * cos(g->player.angle_view) - 1);
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] \
			&& (g->map.map[dist_y][dist_x] != wall))
		return (0);
	return (1);
}

int	check_d_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	if (sin(g->player.angle_view) > 0)
		dist_x = floor(g->player.posf.x - 0.1 * sin(g->player.angle_view));
	else
		dist_x = ceil(g->player.posf.x - 0.1 * sin(g->player.angle_view) - 1);
	if (cos(g->player.angle_view) < 0)
		dist_y = floor(g->player.posf.y + 0.1 * cos(g->player.angle_view));
	else
		dist_y = ceil(g->player.posf.y + 0.1 * cos(g->player.angle_view) - 1);
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] \
			&& (g->map.map[dist_y][dist_x] != wall))
		return (0);
	return (1);
}

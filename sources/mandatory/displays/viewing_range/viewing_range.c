/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:04 by twang             #+#    #+#             */
/*   Updated: 2023/09/26 14:18:35 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	view_left(t_game *g)
{
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view -= M_PI * g->player.diff_pov / 48;
	game_display(g);
	return (0);
}

int	view_right(t_game *g)
{
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view += M_PI * g->player.diff_pov / 48;
	game_display(g);
	return (0);
}

float	get_angle_degree(t_game *g)
{
	float	scalar;

	scalar = g->player.view.x;
	if (g->player.view.y > 0)
		return ((acos(scalar) * 3));
	return (acos(scalar));
}

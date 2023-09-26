/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:58:32 by twang             #+#    #+#             */
/*   Updated: 2023/09/26 14:52:53 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	w_move(t_game *g)
{
	if (check_w_move(g))
		return (0);
	g->player.posf.x = g->player.posf.x + 0.1 * cos(g->player.angle_view);
	g->player.posf.y = g->player.posf.y + 0.1 * sin(g->player.angle_view);
	g->player.pos.x = g->player.posf.x;
	g->player.pos.y = g->player.posf.y;
	game_display(g);
	return (0);
}

int	a_move(t_game *g)
{
	if (check_a_move(g))
		return (0);
	g->player.posf.y = g->player.posf.y - 0.1 * cos(g->player.angle_view);
	g->player.pos.y = g->player.posf.y;
	g->player.posf.x = g->player.posf.x + 0.1 * sin(g->player.angle_view);
	g->player.pos.x = g->player.posf.x;
	game_display(g);
	return (0);
}

int	s_move(t_game *g)
{
	if (check_s_move(g))
		return (0);
	g->player.posf.x = g->player.posf.x - 0.1 * cos(g->player.angle_view);
	g->player.posf.y = g->player.posf.y - 0.1 * sin(g->player.angle_view);
	g->player.pos.x = g->player.posf.x;
	g->player.pos.y = g->player.posf.y;
	game_display(g);
	return (0);
}

int	d_move(t_game *g)
{
	if (check_d_move(g))
		return (0);
	g->player.posf.x = g->player.posf.x - 0.1 * sin(g->player.angle_view);
	g->player.posf.y = g->player.posf.y + 0.1 * cos(g->player.angle_view);
	g->player.pos.x = g->player.posf.x;
	g->player.pos.y = g->player.posf.y;
	game_display(g);
	return (0);
}

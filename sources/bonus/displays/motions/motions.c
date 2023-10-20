/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:58:32 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:39:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	w_move(t_game *g)
{
	if (check_x(g, g->player.posf.x + 0.2 * cos(g->player.angle_view)))
	{
		g->player.posf.x = g->player.posf.x + 0.1 * cos(g->player.angle_view);
		g->player.pos.x = g->player.posf.x;
	}
	if (check_y(g, g->player.posf.y + 0.2 * sin(g->player.angle_view)))
	{
		g->player.posf.y = g->player.posf.y + 0.1 * sin(g->player.angle_view);
		g->player.pos.y = g->player.posf.y;
	}
	return (0);
}

int	a_move(t_game *g)
{
	if (check_x(g, g->player.posf.x + 0.2 * sin(g->player.angle_view)))
	{
		g->player.posf.x = g->player.posf.x + 0.1 * sin(g->player.angle_view);
		g->player.pos.x = g->player.posf.x;
	}
	if (check_y(g, g->player.posf.y - 0.2 * cos(g->player.angle_view)))
	{
		g->player.posf.y = g->player.posf.y - 0.1 * cos(g->player.angle_view);
		g->player.pos.y = g->player.posf.y;
	}
	return (0);
}

int	s_move(t_game *g)
{
	if (check_x(g, g->player.posf.x - 0.2 * cos(g->player.angle_view)))
	{
		g->player.posf.x = g->player.posf.x - 0.1 * cos(g->player.angle_view);
		g->player.pos.x = g->player.posf.x;
	}
	if (check_y(g, g->player.posf.y - 0.2 * sin(g->player.angle_view)))
	{
		g->player.posf.y = g->player.posf.y - 0.1 * sin(g->player.angle_view);
		g->player.pos.y = g->player.posf.y;
	}
	return (0);
}

int	d_move(t_game *g)
{
	if (check_x(g, g->player.posf.x - 0.2 * sin(g->player.angle_view)))
	{
		g->player.posf.x = g->player.posf.x - 0.1 * sin(g->player.angle_view);
		g->player.pos.x = g->player.posf.x;
	}
	if (check_y(g, g->player.posf.y + 0.2 * cos(g->player.angle_view)))
	{
		g->player.posf.y = g->player.posf.y + 0.1 * cos(g->player.angle_view);
		g->player.pos.y = g->player.posf.y;
	}
	return (0);
}

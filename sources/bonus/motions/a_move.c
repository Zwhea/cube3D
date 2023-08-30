/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:00:21 by twang             #+#    #+#             */
/*   Updated: 2023/08/24 12:30:33 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	a_move(t_game *g)
{
	puts(RED"je bouge avec a"END);
	g->player.posf.x = g->player.posf.x + 0.10000 * sin(g->player.angle_view);
	g->player.posf.y = g->player.posf.y - 0.10000 * cos(g->player.angle_view);
	if (g->player.pos.x != g->player.posf.x)
		g->player.pos.x = g->player.posf.x;
	if (g->player.pos.y != g->player.posf.y)
		g->player.pos.y = g->player.posf.y;
	map_render(g);
	return (0);
}

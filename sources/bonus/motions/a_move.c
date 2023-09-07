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
	t_vector	check;
	// if (check_a_move(g))
	// 	return (0);
	puts(RED"je bouge avec a"END);
	g->player.posf.y = g->player.posf.y - 0.1 * cos(g->player.angle_view);
	g->player.pos.y = g->player.posf.y;
	g->player.posf.x = g->player.posf.x + 0.1 * sin(g->player.angle_view);
	g->player.pos.x = g->player.posf.x;
	map_render(g);
	return (0);
}

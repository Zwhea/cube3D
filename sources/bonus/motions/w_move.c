/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:40:46 by twang             #+#    #+#             */
/*   Updated: 2023/08/28 16:28:56 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	w_move(t_game *g)
{
	if (check_w_move(g))
		return (0);
	puts(GREEN"je bouge avec w"END);
	g->player.posf.x = g->player.posf.x + 0.1 * cos(g->player.angle_view);
	g->player.posf.y = g->player.posf.y + 0.1 * sin(g->player.angle_view);
	g->player.pos.x = g->player.posf.x;
	g->player.pos.y = g->player.posf.y;
	map_render(g);
	return (0);
}

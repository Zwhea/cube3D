/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:40:46 by twang             #+#    #+#             */
/*   Updated: 2023/09/04 13:31:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	d_move(t_game *g)
{
	if (check_d_move(g))
		return (0);
	puts(BLUE"je bouge avec d"END);
	g->player.posf.x = g->player.posf.x - 0.1 * sin(g->player.angle_view);
	g->player.posf.y = g->player.posf.y + 0.1 * cos(g->player.angle_view);
	g->player.pos.x = (int)g->player.posf.x;
	g->player.pos.y = (int)g->player.posf.y;
	map_render(g);
	return (0);
}

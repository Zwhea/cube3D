/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:40:46 by twang             #+#    #+#             */
/*   Updated: 2023/08/24 12:30:42 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	s_move(t_game *g)
{
	puts(YELLOW"je bouge avec s"END);
	g->player.posf.y = g->player.posf.y + 0.10000;
	printf("x:%f y:%f\n", g->player.posf.x, g->player.posf.y);
	if (g->player.pos.y != g->player.posf.y)
		g->player.pos.y = g->player.posf.y;
	map_render(g);
	return (0);
}

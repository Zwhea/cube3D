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
	g->player.posf.x = g->player.posf.x - 0.10000;
	printf("x:%f y:%f\n", g->player.posf.x, g->player.posf.y);
	if (g->player.pos.x != g->player.posf.x)
		g->player.pos.x = g->player.posf.x;
	map_render(g);
	return (0);
}

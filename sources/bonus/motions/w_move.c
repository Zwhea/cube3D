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
	// float	test_x;
	// float	test_y;

	// test_x = g->player.posf.x + 0.10000 * cos(g->player.angle_view) * 100;
	// printf("%f ET %d\n", test_x, (int)test_x);
	// test_y = g->player.posf.y + 0.10000 * sin(g->player.angle_view) * 100;
	// if (my_mlx_pixel_get(g, (int)test_x, (int)test_y) == H_GREY)
	// 	return (0);
	puts(GREEN"je bouge avec w"END);
	g->player.posf.x = g->player.posf.x + 0.10000 * cos(g->player.angle_view);
	g->player.posf.y = g->player.posf.y + 0.10000 * sin(g->player.angle_view);
	if (g->player.pos.x != g->player.posf.x)
		g->player.pos.x = g->player.posf.x;
	if (g->player.pos.y != g->player.posf.y)
		g->player.pos.y = g->player.posf.y;
	map_render(g);
	return (0);
}

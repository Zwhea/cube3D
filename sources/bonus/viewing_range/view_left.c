/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:29:44 by twang             #+#    #+#             */
/*   Updated: 2023/08/29 10:37:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	view_left(t_game *g)
{
<<<<<<< HEAD:sources/bonus/render/game/ceiling_n_floor.c
	int	i;

	i = -1;
	// g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	// g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
	// 									&g->draw.line_length, &g->draw.endian);
	while (++i < WINDOW_Y / 2)
	{
		draw_line(g, g->size, g->window_size, g->color[0].color);
		g->size.y++;
	}
	while (++i < WINDOW_Y)
	{
		draw_line(g, g->size, g->window_size, g->color[1].color);
		g->size.y++;
	}
=======
	(void)g;
	puts("je regarde a gauche");
	return (0);
>>>>>>> 66656537bf524d83c7e1b1d7aa2198e24425bca6:sources/bonus/viewing_range/view_left.c
}

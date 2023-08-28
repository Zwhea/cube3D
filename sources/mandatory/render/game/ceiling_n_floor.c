/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_n_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:20:59 by twang             #+#    #+#             */
/*   Updated: 2023/08/28 13:47:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	render_colored_ceil_floor(t_game *g)
{
	int	i;
	
	i = -1;
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
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
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:29:39 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/21 13:10:44 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	mini_map_render(t_game *g)
{
	t_vector	start;
	t_vector	end;

	start.x = 0;
	start.y = 0;
	end.x = MINI_MAP_Y;
	end.y = MINI_MAP_X;
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	fill_background(g, MINI_MAP_X, MINI_MAP_Y, H_WHITE);
	draw_square(g, 50, 50, g->color[0].color);
	draw_line(g, start, end, g->color[1].color);
	mlx_put_image_to_window(g->mlx, g->map_window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:29:39 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/10 12:02:16 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	legend_render(t_game *g)
{
	t_vector	start;
	t_vector	end;

	start.x = 0;
	start.y = 0;
	end.x = LEGEND_Y;
	end.y = LEGEND_X;
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	fill_background(g, LEGEND_X, LEGEND_Y, H_BLUE);
	mlx_put_image_to_window(g->mlx, g->legend_window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

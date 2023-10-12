/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:29:39 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/12 16:03:47 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	legend_render(t_game *g)
{
	(void)g;
	puts("legend is open");
	// g->legend.img = mlx_new_image(g->mlx, LEGEND_X, LEGEND_Y);
	// if (g->legend.img)
	// 	puts("ET BEN");
	// g->draw.addr = mlx_get_data_addr(g->legend.img, &g->draw.bits_per_pixel, \
	// 									&g->draw.line_length, &g->draw.endian);
	// if (g->draw.addr)
	// 	puts("ET BAN");
	// mlx_put_image_to_window(g->mlx, g->legend_window, g->legend.img, 0, 0);
	// mlx_destroy_image(g->mlx, g->legend.img);
}

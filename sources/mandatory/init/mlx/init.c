/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:38:50 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 13:36:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		clean(g);
	set_vector(&g->window_size, WINDOW_X, WINDOW_Y);
	g->window = mlx_new_window(g->mlx, g->window_size.x, g->window_size.y, \
									"cub3D");
	if (g->window == NULL)
		clean(g);
}

void	init_img(t_game *g)
{
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	if (!g->draw.img)
		clean(g);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	if (!g->draw.addr)
		clean(g);
}

void	init_mlx_functions(t_game *g)
{
	mlx_hook(g->window, 2, 1L << 0, key_switch, g);
	mlx_hook(g->window, 3, 1L << 1, key_release, g);
	mlx_loop_hook(g->mlx, key_manager, g);
	mlx_hook(g->window, 17, 1L << 17, clean, g);
	mlx_loop(g->mlx);
}

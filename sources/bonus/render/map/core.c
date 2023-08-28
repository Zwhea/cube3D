/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:47 by aascedu           #+#    #+#             */
/*   Updated: 2023/08/23 08:46:48 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_map(t_game *g)
{
	down_left_corner(g);
	down_right_corner(g);
	up_right_corner(g);
	up_left_corner(g);
	draw_player_map_square(g, 161, 161, H_RED);
}

void	map_render(t_game *g)
{
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	fill_background(g, WINDOW_X, WINDOW_Y, H_GREEN);
	init_map(g);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

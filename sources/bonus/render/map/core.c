
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:47 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/08 13:10:45 by twang            ###   ########.fr       */
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
}

void	map_render(t_game *g)
{
	double	angle;
	double	ratio;

	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	angle = g->player.angle_view - (30 * M_PI / 180);
	ratio = (60 * M_PI / 180) / 1920;
	// printf("dddddd%f\n", angle);
	while (angle <= g->player.angle_view + (30 * M_PI / 180))
	{
		raycasting(g, angle);
		g->size.x++;
		angle += ratio;
		// printf("ICI:%f\n", angle);
	}
	init_map(g);
	show_fov(g);
	draw_circle(g, 155, 155, H_DARKGREEN);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

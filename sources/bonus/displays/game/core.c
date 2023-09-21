/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:35 by twang             #+#    #+#             */
/*   Updated: 2023/09/21 14:04:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_game(t_game *g);

/*----------------------------------------------------------------------------*/

void	game_display(t_game *g)
{
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	_init_game(g);
	minimap_display(g);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

static void	_init_game(t_game *g)
{
	double	angle;
	double	ratio;

	angle = g->player.angle_view - (30 * M_PI / 180);
	ratio = (60 * M_PI / 180) / 1920;
	while (angle <= g->player.angle_view + (30 * M_PI / 180))
	{
		raycasting(g, angle);
		g->size.x++;
		angle += ratio;
	}
}

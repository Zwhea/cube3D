/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:35 by twang             #+#    #+#             */
/*   Updated: 2023/10/19 12:35:20 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_game(t_game *g);

/*----------------------------------------------------------------------------*/

void	game_display(t_game *g)
{
	draw_ceiling_n_floor(g, 1920, 1080, 0);
	door_animations(g);
	_init_game(g);
	draw_crosshair(g);
	draw_hands(g);
	minimap_display(g);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_string_put(g->mlx, g->window, g->mini_map.north.x - 3,
		g->mini_map.north.y + 5, H_RED, "N");
}

static void	_init_game(t_game *g)
{
	double	angle;
	double	ratio;

	angle = g->player.angle_view - (30 * M_PI / 180);
	ratio = (60 * M_PI / 180) / 1920;
	g->size.x = 0;
	while (angle <= g->player.angle_view + (30 * M_PI / 180))
	{
		g->size.y = 0;
		raycasting(g, angle);
		g->size.x++;
		angle += ratio;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:35 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:42:13 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_game(t_game *g);
static void	_help_open(t_game *g);

/*----------------------------------------------------------------------------*/

void	game_display(t_game *g)
{
	draw_ceiling_n_floor(g, 1920, 1080, 0);
	door_animations(g);
	_init_game(g);
	draw_crosshair(g);
	player_animation(g);
	minimap_display(g);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_string_put(g->mlx, g->window, g->mini_map.north.x - 3,
		g->mini_map.north.y + 5, H_RED, "N");
	_help_open(g);
	thx_henri(g);
}

static void	_help_open(t_game *g)
{
	if (g->switches.h_henri == 1)
		return ;
	raycasting(g, g->player.angle_view);
	if (g->ray.dist < 3 && g->map.map[g->ray.check.y][g->ray.check.x] == door)
		mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 60, WINDOW_Y / 2 - 40,
			H_GREEN, "Press Space To Open");
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

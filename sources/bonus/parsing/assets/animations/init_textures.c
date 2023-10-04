/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:01 by twang             #+#    #+#             */
/*   Updated: 2023/10/04 15:39:44 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_door_sprites(t_game *g)
{
	g->animations.door[0].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_00, \
											&g->animations.door[0].width, \
											&g->animations.door[0].height);
	g->animations.door[0].addr = mlx_get_data_addr(g->animations.door[0].img, \
										&g->animations.door[0].bits_per_pixel, \
										&g->animations.door[0].line_length, \
										&g->animations.door[0].endian);
	g->animations.door[1].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_01, \
											&g->animations.door[1].width, \
											&g->animations.door[1].height);
	g->animations.door[1].addr = mlx_get_data_addr(g->animations.door[1].img, \
										&g->animations.door[1].bits_per_pixel, \
										&g->animations.door[1].line_length, \
										&g->animations.door[1].endian);
	g->animations.door[2].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_02, \
											&g->animations.door[2].width, \
											&g->animations.door[2].height);
	g->animations.door[2].addr = mlx_get_data_addr(g->animations.door[2].img, \
										&g->animations.door[2].bits_per_pixel, \
										&g->animations.door[2].line_length, \
										&g->animations.door[2].endian);
}

void	init_player_sprites(t_game *g)
{
	g->animations.player[0].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_00, \
											&g->animations.player[0].width, \
											&g->animations.player[0].height);
	g->animations.player[0].addr = mlx_get_data_addr(g->animations.player[0].img, \
										&g->animations.player[0].bits_per_pixel, \
										&g->animations.player[0].line_length, \
										&g->animations.player[0].endian);
	g->animations.player[1].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_01, \
											&g->animations.player[1].width, \
											&g->animations.player[1].height);
	g->animations.player[1].addr = mlx_get_data_addr(g->animations.player[1].img, \
										&g->animations.player[1].bits_per_pixel, \
										&g->animations.player[1].line_length, \
										&g->animations.player[1].endian);
	g->animations.player[2].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_02, \
											&g->animations.player[2].width, \
											&g->animations.player[2].height);
	g->animations.player[2].addr = mlx_get_data_addr(g->animations.player[2].img, \
										&g->animations.player[2].bits_per_pixel, \
										&g->animations.player[2].line_length, \
										&g->animations.player[2].endian);
}

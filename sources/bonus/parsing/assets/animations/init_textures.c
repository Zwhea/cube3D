/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:01 by twang             #+#    #+#             */
/*   Updated: 2023/10/09 17:09:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_door_sprites(t_game *g)
{
	g->sprites.door[0].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_00, \
											&g->sprites.door[0].width, \
											&g->sprites.door[0].height);
	g->sprites.door[0].addr = mlx_get_data_addr(g->sprites.door[0].img, \
										&g->sprites.door[0].bits_per_pixel, \
										&g->sprites.door[0].line_length, \
										&g->sprites.door[0].endian);
	g->sprites.door[1].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_01, \
											&g->sprites.door[1].width, \
											&g->sprites.door[1].height);
	g->sprites.door[1].addr = mlx_get_data_addr(g->sprites.door[1].img, \
										&g->sprites.door[1].bits_per_pixel, \
										&g->sprites.door[1].line_length, \
										&g->sprites.door[1].endian);
	g->sprites.door[2].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_02, \
											&g->sprites.door[2].width, \
											&g->sprites.door[2].height);
	g->sprites.door[2].addr = mlx_get_data_addr(g->sprites.door[2].img, \
										&g->sprites.door[2].bits_per_pixel, \
										&g->sprites.door[2].line_length, \
										&g->sprites.door[2].endian);
}

void	init_player_sprites(t_game *g)
{
	g->sprites.player[0].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_00, \
											&g->sprites.player[0].width, \
											&g->sprites.player[0].height);
	g->sprites.player[0].addr = mlx_get_data_addr(g->sprites.player[0].img, \
										&g->sprites.player[0].bits_per_pixel, \
										&g->sprites.player[0].line_length, \
										&g->sprites.player[0].endian);
	g->sprites.player[1].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_01, \
											&g->sprites.player[1].width, \
											&g->sprites.player[1].height);
	g->sprites.player[1].addr = mlx_get_data_addr(g->sprites.player[1].img, \
										&g->sprites.player[1].bits_per_pixel, \
										&g->sprites.player[1].line_length, \
										&g->sprites.player[1].endian);
	g->sprites.player[2].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_02, \
											&g->sprites.player[2].width, \
											&g->sprites.player[2].height);
	g->sprites.player[2].addr = mlx_get_data_addr(g->sprites.player[2].img, \
										&g->sprites.player[2].bits_per_pixel, \
										&g->sprites.player[2].line_length, \
										&g->sprites.player[2].endian);
}

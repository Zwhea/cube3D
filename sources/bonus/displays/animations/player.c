/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:08:43 by twang             #+#    #+#             */
/*   Updated: 2023/10/04 15:11:33 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	player_animations(t_game *g)
{
	(void)g;
	puts("hey ca doit mettre des mains yoloooooo");
}

void	init_player_sprites(t_game *g)
{
	g->animations.player[0].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_00, \
											&g->animations.player[0].width, \
											&g->animations.player[0].height);
	g->animations.player[1].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_01, \
											&g->animations.player[1].width, \
											&g->animations.player[1].height);
	g->animations.player[2].img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER_02, \
											&g->animations.player[2].width, \
											&g->animations.player[2].height);
}

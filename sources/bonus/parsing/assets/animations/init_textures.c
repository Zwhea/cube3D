/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:01 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 12:49:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_door_sprites(t_game *g)
{
	init_image(g, &g->sprites, true);
	check_image(g, &g->sprites, true);
	init_image_settings(&g->sprites, true);
	check_image_settings(g, &g->sprites, true);
}

void	init_player_sprites(t_game *g)
{
	init_image(g, &g->sprites, false);
	check_image(g, &g->sprites, false);
	init_image_settings(&g->sprites, false);
	check_image_settings(g, &g->sprites, false);
}

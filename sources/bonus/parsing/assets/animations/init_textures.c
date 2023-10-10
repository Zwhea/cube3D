/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:01 by twang             #+#    #+#             */
/*   Updated: 2023/10/10 11:24:43 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_door_sprites(t_game *g)
{
	init_image(g, &g->sprites, 3, true);
	check_image(g, &g->sprites, 3, true);
	init_image_settings(&g->sprites, 3, true);
	check_image_settings(g, &g->sprites, 3, true);
}

void	init_player_sprites(t_game *g)
{
	init_image(g, &g->sprites, 3, false);
	check_image(g, &g->sprites, 3, false);
	init_image_settings(&g->sprites, 3, false);
	check_image_settings(g, &g->sprites, 3, false);
}

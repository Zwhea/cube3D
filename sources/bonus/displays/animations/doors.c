/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/04 15:12:20 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	door_animations(t_game *g, int door_state)
{
	int	i;

	i = -1;
	while (++i < 500000)
	{
		g->map.map[g->ray.check.y][g->ray.check.x] = h_door;
		if (door_state)
			puts(GREEN"we need to open the door"END);
		else
			puts(RED"we need to close the door"END);
	}
}

void	init_door_sprites(t_game *g)
{
	g->animations.door[0].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_00, \
											&g->animations.door[0].width, \
											&g->animations.door[0].height);
	g->animations.door[1].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_01, \
											&g->animations.door[1].width, \
											&g->animations.door[1].height);
	g->animations.door[2].img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR_02, \
											&g->animations.door[2].width, \
											&g->animations.door[2].height);
}

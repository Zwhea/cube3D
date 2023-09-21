/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:47 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/21 13:59:56 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_minimap(t_game *g);

/*----------------------------------------------------------------------------*/

void	minimap_display(t_game *g)
{
	_init_minimap(g);
	ray_minimap(g, g->player.angle_view);
	draw_circle(g, 155, 155, H_DARKGREEN);
}

static void	_init_minimap(t_game *g)
{
	down_left_corner(g);
	down_right_corner(g);
	up_right_corner(g);
	up_left_corner(g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:39:55 by twang             #+#    #+#             */
/*   Updated: 2023/09/29 09:45:36 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

void	find_dir_wall(t_game *g, int check)
{
	if (check == 1)
	{
		if (g->ray.check.x < g->player.pos.x)
			g->ray.wall_dir = 1;
		else if (g->ray.check.x > g->player.pos.x)
			g->ray.wall_dir = 3;
	}
	else
	{
		if (g->ray.check.y < g->player.pos.y)
			g->ray.wall_dir = 2;
		else if (g->ray.check.y > g->player.pos.y)
			g->ray.wall_dir = 4;
	}
}

void	draw_textures(t_game *g)
{
	if (g->ray.wall && g->ray.wall_dir == 1)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
	else if (g->ray.wall && g->ray.wall_dir == 2)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_BLUE);
	else if (g->ray.wall && g->ray.wall_dir == 3)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_WHITE);
	else if (g->ray.wall && g->ray.wall_dir == 4)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_RED);
	else if (g->ray.door == 1)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
}

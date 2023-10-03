/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:39:55 by twang             #+#    #+#             */
/*   Updated: 2023/10/03 10:56:17 by twang            ###   ########.fr       */
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
			g->ray.wall_dir = west;
		else if (g->ray.check.x > g->player.pos.x)
			g->ray.wall_dir = east;
	}
	else
	{
		if (g->ray.check.y < g->player.pos.y)
			g->ray.wall_dir = north;
		else if (g->ray.check.y > g->player.pos.y)
			g->ray.wall_dir = south;
	}
}

// void	draw_textures(t_game *g)
// {
// 	if (g->ray.wall && g->ray.wall_dir == west)
// 		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
// 	else if (g->ray.wall && g->ray.wall_dir == north)
// 		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_BLUE);
// 	else if (g->ray.wall && g->ray.wall_dir == east)
// 		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_WHITE);
// 	else if (g->ray.wall && g->ray.wall_dir == south)
// 		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_RED);
// 	else if (g->ray.door == 1)
// 		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
// }

void	textures_switchman(t_game *g)
{
	if (g->ray.wall && g->ray.wall_dir == west)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREY);
	else if (g->ray.wall && g->ray.wall_dir == north)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_BLUE);
	else if (g->ray.wall && g->ray.wall_dir == east)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_WHITE);
	else if (g->ray.wall && g->ray.wall_dir == south)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_RED);
	else if (g->ray.door == 1)
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
}

static void	_draw_textures(t_game *g, int wall_dir)
{
	_texturing_vertical(g, wall_dir);
	_texturing_horizontal(g, wall_dir);
}

static void	_texturing_vertical(t_game *g, int wall_dir)
{
	
}

static void	_texturing_vertical(t_game *g, int wall_dir)
{
	
}

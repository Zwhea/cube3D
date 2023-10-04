/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:39:55 by twang             #+#    #+#             */
/*   Updated: 2023/10/04 11:16:04 by twang            ###   ########.fr       */
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

static void	_texturing_vertical(t_game *g)
{
	double		wall_x;
	double		ratio;
	t_vector	texture;
	unsigned int	color;

	if (g->ray.wall_dir == east)
	{
		ratio = g->textures.walls[east_texture].width / g->ray.wall_size;
		wall_x = g->ray.ray_start.y + g->ray.dist * g->ray.ray_dir.y;
		wall_x = wall_x - floor(wall_x);
		texture.x = wall_x * g->textures.walls[east_texture].width;
		texture.x = g->textures.walls[east_texture].width - texture.x - 1;
		texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size) * (g->textures.walls[east_texture].width / 2) / g->ray.wall_size;
		color = my_mlx_pixel_get(&g->textures.walls[east_texture], texture.x, texture.y);
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, color);
	}
	else
	{
		ratio = g->textures.walls[west_texture].width / g->ray.wall_size;
		wall_x = g->ray.ray_start.y + g->ray.dist * g->ray.ray_dir.y;
		wall_x = wall_x - floor(wall_x);
		texture.x = wall_x * g->textures.walls[west_texture].width;
		texture.x = g->textures.walls[west_texture].width - texture.x - 1;
		texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size) * (g->textures.walls[west_texture].width / 2) / g->ray.wall_size;
		color = my_mlx_pixel_get(&g->textures.walls[west_texture], texture.x, texture.y);
		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, color);
	}
}

// ICI texture.x et texture.y sont les coordonnes sur la texture pour trouver la couleur que l'on veut afficher !

static void	_texturing_horizontal(t_game *g)
{
	double		wall_x;
	t_vector	texture;

	wall_x = g->ray.ray_start.y + g->ray.dist * g->ray.ray_dir.y;
	wall_x = wall_x - floor(wall_x);
	texture.x = wall_x * g->textures.walls[north_texture].width;
	texture.x = g->textures.walls[north_texture].width - texture.x - 1;
	texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size) * (g->textures.walls[north_texture].width / 2) / g->ray.wall_size;
	// printf("x=%d y=%d\n", texture.x, texture.y);
	// my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, );
}

void	draw_textures(t_game *g)
{
	if (g->ray.wall_dir == north || g->ray.wall_dir == south)
		_texturing_horizontal(g);
	else
		_texturing_vertical(g);
}

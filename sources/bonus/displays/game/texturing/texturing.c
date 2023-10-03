/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:39:55 by twang             #+#    #+#             */
/*   Updated: 2023/10/03 12:55:20 by twang            ###   ########.fr       */
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

void	draw_textures(t_game *g)
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

<<<<<<< HEAD
static void	_texturing_vertical(t_game *g)
{
	double		wall_x;
	t_vector	texture;

	wall_x = g->ray.ray_start.y + g->ray.dist * g->ray.ray_dir.y;
	wall_x = wall_x - floor(wall_x);
	texture.x = wall_x * g->textures.size[north_texture].x;
	texture.x = g->textures.size[north_texture].x - texture.x - 1;
	texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size) * (g->textures.size[north_texture].x / 2) / g->ray.wall_size;
	// printf("x=%d y=%d\n", texture.x, texture.y);
	my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, my_mlx_pixel_get(g, texture.x, texture.y));
}

// ICI texture.x et texture.y sont les coordonnes sur la texture pour trouver la couleur que l'on veut afficher !

static void	_texturing_horizontal(t_game *g)
{
	double		wall_x;
	t_vector	texture;

	wall_x = g->ray.ray_start.y + g->ray.dist * g->ray.ray_dir.y;
	wall_x = wall_x - floor(wall_x);
	texture.x = wall_x * g->textures.size[north_texture].x;
	texture.x = g->textures.size[north_texture].x - texture.x - 1;
	texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size) * (g->textures.size[north_texture].x / 2) / g->ray.wall_size;
	// printf("x=%d y=%d\n", texture.x, texture.y);
	my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, );
}

void	draw_textures(t_game *g)
{
	if (g->ray.wall_dir == north || g->ray.wall_dir == south)
		_texturing_horizontal(g);
	else
		_texturing_vertical(g);
}
=======
// void	textures_switchman(t_game *g)
// {
// 	if (g->ray.wall && g->ray.wall_dir == west)
// 		_draw_textures(g, west);
// 	else if (g->ray.wall && g->ray.wall_dir == north)
// 		_draw_textures(g, north);
// 	else if (g->ray.wall && g->ray.wall_dir == east)
// 		_draw_textures(g, east);
// 	else if (g->ray.wall && g->ray.wall_dir == south)
// 		_draw_textures(g, south);
// 	else if (g->ray.door == 1)
// 		my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, H_GREEN);
// }

// static void	_draw_textures(t_game *g)
// {
// 	_texturing_vertical(g);
// 	_texturing_horizontal(g);
// }

// static void	_texturing_vertical(t_game *g)
// {
// 	g->textures.h_ratio = g->textures.size.y * g->ray.wall_size;
// 	while ()
// }

// static void	_texturing_horizontal(t_game *g)
// {
// }
>>>>>>> d1dc7fa948b650fadff1ab1efcd80828ce658a30

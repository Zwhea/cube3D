/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:39:55 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 14:20:34 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void					_texturing_vertical(t_game *g);
static void					_texturing_horizontal(t_game *g);
static unsigned int			_texturing_side(t_game *g);

/*----------------------------------------------------------------------------*/

void	draw_textures(t_game *g)
{
	if (g->ray.wall_dir == north || g->ray.wall_dir == south)
		_texturing_horizontal(g);
	else if (g->ray.wall_dir == east || g->ray.wall_dir == west)
		_texturing_vertical(g);
}

static void	_texturing_vertical(t_game *g)
{
	double			wall_x;
	t_vector		texture;
	unsigned int	color;

	if (g->ray.side)
		color = _texturing_side(g);
	wall_x = g->ray.intersection.y - floor(g->ray.intersection.y);
	texture.x = wall_x * g->textures.walls[north_texture].width;
	texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size)
		* (g->textures.walls[north_texture].width / 2) / g->ray.wall_size;
	if (g->ray.wall && g->ray.wall_dir == east)
		color = my_mlx_pix_get(&g->textures.walls[east_texture], \
				texture.x, texture.y);
	else if (g->ray.wall && g->ray.wall_dir == west)
		color = my_mlx_pix_get(&g->textures.walls[west_texture], \
				texture.x, texture.y);
	else if (g->ray.door && g->ray.side == 0)
		color = get_door_color(g, texture, wall_x);
	color = (color >> 1) & 8355711;
	color = get_shade(g, color);
	my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, color);
}

static void	_texturing_horizontal(t_game *g)
{
	double			wall_x;
	t_vector		texture;
	unsigned int	color;

	if (g->ray.side)
		color = _texturing_side(g);
	wall_x = g->ray.intersection.x - floor(g->ray.intersection.x);
	wall_x = wall_x - floor(wall_x);
	texture.x = wall_x * g->textures.walls[north_texture].width;
	texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size)
		* (g->textures.walls[north_texture].width / 2) / g->ray.wall_size;
	if (g->ray.wall && g->ray.wall_dir == north)
		color = my_mlx_pix_get(&g->textures.walls[north_texture], \
				texture.x, texture.y);
	else if (g->ray.wall && g->ray.wall_dir == south)
		color = my_mlx_pix_get(&g->textures.walls[south_texture], \
				texture.x, texture.y);
	else if (g->ray.door && g->ray.side == 0)
		color = get_door_color(g, texture, wall_x);
	color = get_shade(g, color);
	my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, color);
}

static unsigned int	_texturing_side(t_game *g)
{
	t_vector		text;
	unsigned int	color;

	color = 0;
	if (g->ray.wall_dir == north || g->ray.wall_dir == west)
		text.x = (1 - g->ray.f.y) * g->textures.walls[north_texture].width;
	else if (g->ray.wall_dir == south || g->ray.wall_dir == east)
		text.x = (g->ray.f.y) * g->textures.walls[north_texture].width;
	text.y = (g->size.y * 2 - 1080 + g->ray.wall_size)
		* (g->textures.walls[north_texture].width / 2) / g->ray.wall_size;
	if (g->ray.wall_dir == north)
		color = my_mlx_pix_get(&g->textures.walls[west_texture], \
					text.x, text.y);
	else if (g->ray.wall_dir == west)
		color = my_mlx_pix_get(&g->textures.walls[south_texture], \
					text.x, text.y);
	else if (g->ray.wall_dir == south)
		color = my_mlx_pix_get(&g->textures.walls[east_texture], \
					text.x, text.y);
	else if (g->ray.wall_dir == east)
		color = my_mlx_pix_get(&g->textures.walls[north_texture], \
					text.x, text.y);
	return (color);
}

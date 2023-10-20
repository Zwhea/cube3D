/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:39:55 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 13:25:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void			_texturing_vertical(t_game *g);
static void			_texturing_horizontal(t_game *g);
static unsigned int	_get_shade(t_game *game, unsigned int color);

/*----------------------------------------------------------------------------*/

void	find_dir_wall(t_game *g, int check)
{
	if (check == 1)
	{
		if (g->ray.check.x < g->player.pos.x)
			g->ray.wall_dir = west;
		else if (g->ray.check.x > g->player.pos.x)
			g->ray.wall_dir = east;
		g->ray.intersection.x = g->ray.ray_len.x - g->ray.ray_unit.x;
		g->ray.intersection.y = g->ray.ray_len.y;
	}
	else
	{
		if (g->ray.check.y < g->player.pos.y)
			g->ray.wall_dir = north;
		else if (g->ray.check.y > g->player.pos.y)
			g->ray.wall_dir = south;
		g->ray.intersection.x = g->ray.ray_len.x;
		g->ray.intersection.y = g->ray.ray_len.y - g->ray.ray_unit.y;
	}
}

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

	wall_x = g->ray.intersection.y;
	wall_x = wall_x - floor(wall_x);
	texture.x = wall_x * g->textures.walls[north_texture].width;
	texture.y = (g->size.y * 2 - 1080 + g->ray.wall_size)
		* (g->textures.walls[north_texture].width / 2) / g->ray.wall_size;
	if (g->ray.wall && g->ray.wall_dir == east)
		color = my_mlx_pix_get(&g->textures.walls[east_texture], \
				texture.x, texture.y);
	else if (g->ray.wall && g->ray.wall_dir == west)
		color = my_mlx_pix_get(&g->textures.walls[west_texture], \
				texture.x, texture.y);
	else
		color = 0;
	color = (color >> 1) & 8355711;
	color = _get_shade(g, color);
	my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, color);
}

static void	_texturing_horizontal(t_game *g)
{
	double			wall_x;
	t_vector		texture;
	unsigned int	color;

	wall_x = g->ray.intersection.x;
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
	else
		color = 0;
	color = (color >> 1) & 8355711;
	color = _get_shade(g, color);
	my_mlx_pixel_put(&g->draw, g->size.x, g->size.y, color);
}

static unsigned int	_get_shade(t_game *game, unsigned int color)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	if (game->ray.dist > 6)
	{
		ratio = 1 - ((game->ray.dist - 6) * 0.1);
		r = (int)(r * ratio);
		g = (int)(g * ratio);
		b = (int)(b * ratio);
	}
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

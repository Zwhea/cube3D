/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:20 by twang             #+#    #+#             */
/*   Updated: 2023/08/09 16:36:30 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_map_key_press(t_keycode key, t_game *g);
static void	_mini_map_render(t_game *g);
static void	_draw_square(t_game *g, int x, int y, int color);
static void	_draw_line(t_game *g, t_vector start, t_vector end, int color);

/*----------------------------------------------------------------------------*/

void	mini_map_init(t_game *g)
{
	if (g->map_window)
	{
		mlx_destroy_window(g->mlx, g->map_window);
		g->map_window = NULL;
		return ;
	}
	set_vector(&g->map_window_size, MINI_MAP_X, MINI_MAP_Y);
	g->map_window = mlx_new_window(g->mlx, g->map_window_size.x, \
									g->map_window_size.y, "mini_map");
	if (!g->map_window)
		clean(g);
	_mini_map_render(g);
	mlx_key_hook(g->map_window, _map_key_press, g);
	mlx_hook(g->map_window, 17, 1L << 17, clean_mini_map, g);
}

static int	_map_key_press(t_keycode key, t_game *g)
{
	if (key == esc_key || key == m_key)
		clean_mini_map(g);
	return (0);
}

static void	_mini_map_render(t_game *g)
{
	t_vector	start;
	t_vector	end;

	start.x = 0;
	start.y = 0;
	end.x = MINI_MAP_Y;
	end.y = MINI_MAP_X;
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	_draw_square(g, 50, 50, H_WHITE);
	_draw_line(g, start, end, H_WHITE);
	mlx_put_image_to_window(g->mlx, g->map_window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

static void	_draw_line(t_game *g, t_vector start, t_vector end, int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;
	
	dx = end.x - start.x;
	dy = end.y - end.x;
	x = start.x;
	y = start.y;
	p = 2 * dy - dx;
	while (x < end.x)
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(&g->draw, x, y, color);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(&g->draw, x, y, color);
			p = p + 2 * dy;
			x = x + 1;
		}
	}
}

static void	_draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			my_mlx_pixel_put(&g->draw, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
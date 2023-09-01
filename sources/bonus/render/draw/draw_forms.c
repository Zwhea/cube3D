/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:26:46 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/01 18:22:12 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	draw_frame(t_game *g, int size_x, int size_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_x)
	{
		j = 0;
		while (j < size_y)
		{
			if (i % 30 == 0 || j % 30 == 0)
				my_mlx_pixel_put(&g->draw, i, j, color);
			if (i < 5 || j < 5 || j > size_y - 5 || i > size_x - 5)
				my_mlx_pixel_put(&g->draw, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 30)
	{
		j = 0;
		while (j <= 30)
		{
			if (x + j <= 30 + MINI_MAP_X && x + j >= 30 \
				&& y + i <= 30 + MINI_MAP_Y && y + i >= 30)
				my_mlx_pixel_put(&g->draw, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_game *g, int x, int y, int color)
{
	int		i;
	int		j;
	float	dst;

	i = 0;
	while (i <= 20)
	{
		j = 0;
		while (j <= 20)
		{
			dst = sqrt(pow((i - 10), 2) + pow((j - 10), 2));
			if (dst < 5)
				my_mlx_pixel_put(&g->draw, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_v_rectangle(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 30)
	{
		j = -1;
		while (++j <= 10)
			if (x + j <= 30 + MINI_MAP_X && x + j >= 30 \
				&& y + i <= 30 + MINI_MAP_Y && y + i >= 30)
				my_mlx_pixel_put(&g->draw, x + j, y + i, H_WHITE);
		while (++j <= 20)
			if (x + j <= 30 + MINI_MAP_X && x + j >= 30 \
				&& y + i <= 30 + MINI_MAP_Y && y + i >= 30)
				my_mlx_pixel_put(&g->draw, x + j, y + i, color);
		while (++j <= 30)
			if (x + j <= 30 + MINI_MAP_X && x + j >= 30 \
				&& y + i <= 30 + MINI_MAP_Y && y + i >= 30)
				my_mlx_pixel_put(&g->draw, x + j, y + i, H_WHITE);
	}
}

void	draw_h_rectangle(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 30)
	{
		if (i >= 10 && i <= 20)
		{
			j = -1;
			while (++j <= 30)
				if (x + j <= 30 + MINI_MAP_X && x + j >= 30 \
					&& y + i <= 30 + MINI_MAP_Y && y + i >= 30)
					my_mlx_pixel_put(&g->draw, x + j, y + i, color);
		}
		else
		{
			j = -1;
			while (++j <= 30)
				if (x + j <= 30 + MINI_MAP_X && x + j >= 30 \
					&& y + i <= 30 + MINI_MAP_Y && y + i >= 30)
					my_mlx_pixel_put(&g->draw, x + j, y + i, H_WHITE);
		}
	}
}

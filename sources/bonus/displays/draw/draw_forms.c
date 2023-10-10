/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:26:46 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/09 17:10:32 by twang            ###   ########.fr       */
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

void	draw_circle(t_game *g, t_vector *pos, int rayon, int color)
{
	t_vector	indic;

	set_vector(&indic, pos->x - rayon, pos->y - rayon);
	while (indic.y < rayon + pos->y)
	{
		indic.x = pos->x - rayon;
		while (indic.x < rayon + pos->x)
		{
			if (((indic.x - pos->x) * (indic.x - pos->x)) \
				+ ((indic.y - pos->y) * (indic.y - pos->y)) < (rayon * rayon))
				my_mlx_pixel_put(&g->draw, indic.x, indic.y, color);
			indic.x++;
		}
		indic.y++;
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

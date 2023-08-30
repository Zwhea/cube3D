/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:26:46 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/30 09:28:22 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	draw_square_map(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (x + j <= 30 + MINI_MAP_X && x + j >= 30 && y + i <= 30 + MINI_MAP_Y && y + i >= 30)
				my_mlx_pixel_put(&g->draw, x + j, y + i, color);
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
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			my_mlx_pixel_put(&g->draw, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player_map_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put(&g->draw, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

// void	draw_circle(t_game *g, int x, int y, int color)
// {
// 	int		i;
// 	int		j;
// 	float	dst;
	
// 	i = 0;
// 	while (i < 20)
// 	{
// 		j = 0;
// 		while (j < 20)
// 		{
// 			dst = sqrt(pow((j - x), 2) + pow((i - y), 2));
// 			if (dst < 5)
// 				my_mlx_pixel_put(&g->draw, j + x, i + y, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_circle(t_game *g, int x, int y, int color)
{
	int	x1;
	int	y1;

	x1 = 0;
	while (x1 <= 20)
	{
		y1 = 0;
		while (y1 <= 20)
		{
			if (25 == pow((x1 - x), 2) + pow((y1 - y), 2))
				my_mlx_pixel_put(&g->draw, x1 + x, y1 + 1, H_RED);
			y1++;
		}
		x1++;
	}
}
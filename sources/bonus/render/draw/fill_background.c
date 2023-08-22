/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:51:33 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/10 12:01:56 by wangthea         ###   ########.fr       */
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
			if (i <= 4 || j <= 4 || j >= size_y - 5 || i >= size_x - 5)
				my_mlx_pixel_put(&g->draw, i, j, color);
			j++;
		}
		i++;
	}
}

void	fill_background(t_game *g, int size_x, int size_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_x)
	{
		j = 0;
		while (j < size_y)
		{
			my_mlx_pixel_put(&g->draw, i, j, color);
			j++;
		}
		i++;
	}
}

void	init_map(t_game *g, int x, int y)
{
	int	i;

	i = x;
	printf("x=%d et y=%d\nmap: %c\n", x, y, g->map.map[y][i]);
	while (i > x - 5 && i >= 0)
	{
		if (g->map.map[i][y] == wall)
			draw_square(g, 140 - (27 * (x - i)), 140, H_RED);
		if (g->map.map[i][y] == space)
			draw_square(g, 140 - (27 * (x - i)), 140, H_WHITE);
		i--;
	}
}
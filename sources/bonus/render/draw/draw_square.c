/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:26:46 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/10 10:33:06 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

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
			if (x + j <= 30 + MINI_MAP_X && x + j >= 30 && y + i <= 30 + MINI_MAP_Y && y + i >= 30)
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

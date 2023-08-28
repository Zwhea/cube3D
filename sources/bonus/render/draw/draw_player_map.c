/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:41:37 by aascedu           #+#    #+#             */
/*   Updated: 2023/08/28 07:41:38 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	draw_player_square_map(t_game *g, int r)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	while (pos_x <= MINI_MAP_X)
	{
		pos_y = 0;
		while (pos_y <= MINI_MAP_Y)
		{
			if (pow(r, 2) == 36450 + pow(pos_x, 2) + pow(pos_y, 2) - \
				(270 * pos_x) - (270 * pos_y))
				my_mlx_pixel_put(&g->draw, pos_x, pos_y, H_RED);
			pos_y = pos_y + 1;
		}
		pos_x = pos_x + 1;
	}
}

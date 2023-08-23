/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:47:07 by aascedu           #+#    #+#             */
/*   Updated: 2023/08/23 08:47:08 by aascedu          ###   ########.fr       */
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
				my_mlx_pixel_put(&g->draw, i, j, H_PINK);
			if (i < 5 || j < 5 || j > size_y - 5 || i > size_x - 5)
				my_mlx_pixel_put(&g->draw, i, j, color);
			j++;
		}
		i++;
	}
}

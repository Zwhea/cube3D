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

static unsigned int	_shade_background_2(int j, unsigned int color)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	if (j <= 790)
	{
		ratio = 1 - ((790 - j) * 0.003);
		r = (int)(r * ratio);
		g = (int)(g * ratio);
		b = (int)(b * ratio);
	}
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static unsigned int	_shade_background_1(int j, unsigned int color)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	if (j >= 250)
	{
		ratio = 1 - ((j - 250) * 0.003);
		r = (int)(r * ratio);
		g = (int)(g * ratio);
		b = (int)(b * ratio);
	}
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
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
			if (j <= 539)
			{
				color = _shade_background_1(j, H_BLUE);
				my_mlx_pixel_put(&g->draw, i, j, color);
			}
			else
			{
				color = _shade_background_2(j, H_GREY);
				my_mlx_pixel_put(&g->draw, i, j, color);
			}
			j++;
		}
		i++;
	}
}

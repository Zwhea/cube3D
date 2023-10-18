/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_n_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:59 by twang             #+#    #+#             */
/*   Updated: 2023/10/12 15:44:04 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned int	_shade_floor(int j, unsigned int color)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	if (j <= 890)
	{
		ratio = 1 - ((890 - j) * 0.003);
		r = (int)(r * ratio);
		g = (int)(g * ratio);
		b = (int)(b * ratio);
	}
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static unsigned int	_shade_ceiling(int j, unsigned int color)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	if (j >= 150)
	{
		ratio = 1 - ((j - 150) * 0.003);
		r = (int)(r * ratio);
		g = (int)(g * ratio);
		b = (int)(b * ratio);
	}
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	draw_ceiling_n_floor(t_game *g, int size_x, int size_y, int color)
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
				color = _shade_ceiling(j, g->color[0].color);
				my_mlx_pixel_put(&g->draw, i, j, color);
			}
			else
			{
				color = _shade_floor(j, g->color[1].color);
				my_mlx_pixel_put(&g->draw, i, j, color);
			}
			j++;
		}
		i++;
	}
}

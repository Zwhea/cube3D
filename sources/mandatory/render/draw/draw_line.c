/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:27:05 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/10 12:04:48 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	draw_line(t_game *g, t_vector start, t_vector end, int color)
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

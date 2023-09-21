/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:50:18 by twang             #+#    #+#             */
/*   Updated: 2023/09/21 09:39:52 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

float	get_angle_degree(t_game *g)
{
	float	scalar;

	scalar = g->player.view.x;
	if (g->player.view.y > 0)
		return ((acos(scalar) * 3));
	return (acos(scalar));
}

void	ray_minimap(t_game *g, float angle)
{
	float	plane_y;
	float	throw_x;
	float	throw_y;
	float	degree;

	degree = angle + M_PI / 6;
	while (degree >= angle - M_PI / 6)
	{
		plane_y = 0;
		while (plane_y <= 165)
		{
			throw_x = 165 + plane_y * cos(degree);
			throw_y = 165 + plane_y * sin(degree);
			if (my_mlx_pixel_get(g, throw_x, throw_y) == H_BLACK || \
				my_mlx_pixel_get(g, throw_x, throw_y) == H_GREY)
				break ;
			if (throw_x >= 0 && throw_y >= 0)
				my_mlx_pixel_put(&g->draw, (int)throw_x, (int)throw_y, H_GREEN);
			plane_y++;
		}
		degree = degree - M_PI / 768;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:26:46 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/20 15:11:09 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

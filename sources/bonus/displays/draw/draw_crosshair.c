/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:41:39 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 15:36:43 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_crosshair(t_game *g)
{
	int	i;

	i = 529;
	while (++i <= 550)
		my_mlx_pixel_put(&g->draw, 960, i, H_WHITE);
	i = 529;
	while (++i <= 550)
		my_mlx_pixel_put(&g->draw, 959, i, H_WHITE);
	i = 529;
	while (++i <= 550)
		my_mlx_pixel_put(&g->draw, 961, i, H_WHITE);
	i = 949;
	while (++i <= 970)
		my_mlx_pixel_put(&g->draw, i, 540, H_WHITE);
	i = 949;
	while (++i <= 970)
		my_mlx_pixel_put(&g->draw, i, 541, H_WHITE);
	i = 949;
	while (++i <= 970)
		my_mlx_pixel_put(&g->draw, i, 539, H_WHITE);
}

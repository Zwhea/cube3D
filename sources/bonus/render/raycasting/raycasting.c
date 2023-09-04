/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:05:31 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/04 13:05:32 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	get_posf_wall(t_game *g)
{
	int	delta_x;
	int	delta_y;
	int		wall;

	wall = 0;
	delta_x = (int)(g->player.posf.x * 10);
	delta_y = (int)(g->player.posf.y * 10);
	printf("dX = %d dY = %d\n", delta_x, delta_y);
	while (wall == 0)
	{
		delta_x += cos(g->player.angle_view);
		delta_y += sin(g->player.angle_view);
	printf("map[%d][%d]=%c\n", delta_y / 10, delta_x / 10, g->map.map[delta_y / 10][delta_x / 10]);
		if (g->map.map[delta_y / 10][delta_x / 10] == '1')
			wall = 1;
	}
	printf("%d\n", sqrt(pow(delta_x - g->player.posf.x, 2) + pow(delta_y - g->player.posf.y, 2)));
	return (sqrt(pow(delta_x - (int)g->player.posf.x, 2) + pow(delta_y - (int)g->player.posf.y, 2)));
}

void	raycasting(t_game *g)
{
	int	x;
	int	y;
	int	under_y;

	x = 960;
	y = 540;
	under_y = (get_posf_wall(g) * 10) * cos(30);
	while (y >= 0)
	{
		if (y >= under_y)
			my_mlx_pixel_put(&g->draw, x, y, H_BLUE);
		else
			my_mlx_pixel_put(&g->draw, x, y, H_GREY);
		y--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:53:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/10 13:53:24 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	draw_hands(t_game *g)
{
	int				x_text;
	int				y_text;
	unsigned int	color;

	x_text = 0;
	while (x_text < g->sprites.player[0].width * 4)
	{
		y_text = 0;
		while (y_text < g->sprites.player[0].width * 4)
		{
			color = my_mlx_pix_get(&g->sprites.player[0], \
				x_text / 4, y_text / 4);
			if (color != H_GREEN)
				my_mlx_pixel_put(&g->draw, ((1920 * 0.5) - 4
						* g->sprites.player[0].width - 1) + y_text,
					(1080 - 4 * g->sprites.player[0].width + 15) + x_text
					+ (int)(cos(g->player.hand_move) * 10), color);
			y_text++;
		}
		x_text++;
	}
}

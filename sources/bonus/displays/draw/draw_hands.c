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

static void	_get_hand_pos(t_game *g)
{
	if ((g->switches.w_key || g->switches.a_key || g->switches.d_key
			|| g->switches.s_key || g->switches.down_key || g->switches.up_key)
		&& g->player.hand_move + (M_PI * 0.125) > 2 * M_PI)
		g->player.hand_move = 0;
	else if (g->switches.w_key || g->switches.a_key || g->switches.d_key
		|| g->switches.s_key || g->switches.down_key || g->switches.up_key)
		g->player.hand_move += (M_PI * 0.125);
}

void	draw_hands(t_game *g)
{
	int				x_text;
	int				y_text;
	unsigned int	color;

	_get_hand_pos(g);
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

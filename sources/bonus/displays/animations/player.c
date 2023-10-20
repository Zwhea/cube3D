/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:53:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 15:29:19 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_get_hand_pos(t_game *g);

/*----------------------------------------------------------------------------*/

void	player_animation(t_game *g)
{
	int				x_text;
	int				y_text;
	unsigned int	color;

	_get_hand_pos(g);
	x_text = 0;
	while (x_text < g->sprites.player.width)
	{
		y_text = 0;
		while (y_text < g->sprites.player.height)
		{
			color = my_mlx_pix_get(&g->sprites.player, x_text, y_text);
			if (color != H_GREEN && \
				(y_text + (int)(cos(g->player.hand_move) * 10) + 10) < WINDOW_Y)
				my_mlx_pixel_put(&g->draw, x_text, y_text \
					+ (int)(cos(g->player.hand_move) * 10) + 10, color);
			y_text++;
		}
		x_text++;
	}
}

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

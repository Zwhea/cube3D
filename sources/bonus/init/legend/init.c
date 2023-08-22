/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:20 by twang             #+#    #+#             */
/*   Updated: 2023/08/21 13:24:07 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_legend_key_press(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

void	legend_init(t_game *g)
{
	if (g->legend_window)
		clean_legend(g);
	else
	{
		set_vector(&g->legend_window_size, LEGEND_X, LEGEND_Y);
		g->legend_window = mlx_new_window(g->mlx, g->legend_window_size.x, \
									g->legend_window_size.y, "legend");
		if (!g->legend_window)
			clean(g);
		legend_render(g);
		mlx_key_hook(g->legend_window, _legend_key_press, g);
		mlx_hook(g->legend_window, 17, 1L << 17, clean_legend, g);
	}
}

static int	_legend_key_press(t_keycode key, t_game *g)
{
	if (key == esc_key || key == l_key)
		clean_legend(g);
	return (0);
}

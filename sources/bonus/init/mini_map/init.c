/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:20 by twang             #+#    #+#             */
/*   Updated: 2023/08/21 14:09:03 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_map_key_press(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

void	mini_map_init(t_game *g)
{
	if (g->map_window)
		clean_mini_map(g);
	else
	{
		set_vector(&g->map_window_size, MINI_MAP_X, MINI_MAP_Y);
		g->map_window = mlx_new_window(g->mlx, g->map_window_size.x, \
									g->map_window_size.y, "mini_map");
		if (!g->map_window)
			clean(g);
		mini_map_render(g);
		mlx_key_hook(g->map_window, _map_key_press, g);
		mlx_hook(g->map_window, 17, 1L << 17, clean_mini_map, g);
	}
}

static int	_map_key_press(t_keycode key, t_game *g)
{
	if (key == esc_key || key == m_key)
		clean_mini_map(g);
	else if (key == l_key)
		legend_init(g);
	return (0);
}

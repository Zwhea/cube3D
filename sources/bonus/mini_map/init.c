/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:20 by twang             #+#    #+#             */
/*   Updated: 2023/08/06 15:20:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	mini_map_init(t_game *g)
{
	void	*n_map_window;

	n_map_window = NULL;
	if (g->map_window)
	{
		mlx_destroy_window(g->mlx, g->map_window);
		g->map_window = n_map_window;
		return ;
	}
	set_vector(&g->map_window_size, MINI_MAP_X, MINI_MAP_Y);
	g->map_window = mlx_new_window(g->mlx, g->map_window_size.x, \
									g->map_window_size.y, "mini_map");
	if (!g->map_window)
		clean(g);
}

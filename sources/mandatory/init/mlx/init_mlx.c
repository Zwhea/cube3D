/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:38:50 by twang             #+#    #+#             */
/*   Updated: 2023/08/10 12:05:07 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	init_mlx(t_game *g)
{
	set_vector(&g->window_size, WINDOW_X, WINDOW_Y);
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		clean(g);
	g->window = mlx_new_window(g->mlx, g->window_size.x, g->window_size.y, \
									"Cub3D");
	if (g->window == NULL)
		clean(g);
}

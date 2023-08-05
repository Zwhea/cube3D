/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:38:50 by twang             #+#    #+#             */
/*   Updated: 2023/08/05 14:04:25 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	init_mlx(t_game *g)
{
	set_vector(&g->window_size, 500, 500);
	/*to change cause i don't know definitive size yet*/
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		clean(g);
	g->window = mlx_new_window(g->mlx, g->window_size.x, g->window_size.y, \
		"Cub3D");
	if (g->window == NULL)
		clean(g);
}

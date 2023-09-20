/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:38:50 by twang             #+#    #+#             */
/*   Updated: 2023/09/20 16:07:57 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

static int	_key_manager(t_game *g);

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		clean(g);
	set_vector(&g->window_size, WINDOW_X, WINDOW_Y);
	g->window = mlx_new_window(g->mlx, g->window_size.x, g->window_size.y, \
									"Cub3D");
	if (g->window == NULL)
		clean(g);
}

void	init_mlx_functions(t_game *g)
{
	mlx_hook(g->window, 2, 1L << 0, key_switch, g);
	mlx_hook(g->window, 3, 1L << 1, key_release, g);
	mlx_hook(g->window, 4, 1L << 2, mouse_switch, g);
	mlx_hook(g->window, 5, 1L << 3, mouse_release, g);
	mlx_hook(g->window, 6, 1L << 6, mouse_move, g);
	// mlx_key_hook(g->window, key_press, g);
	mlx_loop_hook(g->mlx, _key_manager, g);
	mlx_hook(g->window, 17, 1L << 17, clean, g);
	mlx_loop(g->mlx);
}

static int	_key_manager(t_game *g)
{
	if (g->switches.w_key)
		w_move(g);
	if (g->switches.a_key)
		a_move(g);
	if (g->switches.s_key)
		s_move(g);
	if (g->switches.d_key)
		d_move(g);
	if (g->switches.up_key)
		w_move(g);
	if (g->switches.down_key)
		s_move(g);
	if (g->switches.left_key)
		view_left(g);
	if (g->switches.right_key)
		view_right(g);
	return (0);
}

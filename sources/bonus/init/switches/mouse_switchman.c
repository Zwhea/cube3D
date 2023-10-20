/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:40:31 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:34:42 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_mouse_check(t_game *g);

/*----------------------------------------------------------------------------*/

int	mouse_switch(t_keycode key, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (key == m_left_key)
		open_door(g);
	if (key == m_right_key)
		g->switches.mouse = true;
	return (0);
}

int	mouse_move(int x, int y, t_game *g)
{
	(void)y;
	if (g->switches.mouse == true)
		return (0);
	_mouse_check(g);
	if (g->player.last_pov > x + 0.5)
	{
		g->player.diff_pov = (g->player.last_pov - x) / 5;
		if (g->player.diff_pov * 6 < WINDOW_X / 2 + 1)
			view_left(g);
	}
	if (g->player.last_pov < x - 0.5)
	{
		g->player.diff_pov = (x - g->player.last_pov) / 5;
		if (g->player.diff_pov * 6 < WINDOW_X / 2 + 1)
			view_right(g);
	}
	g->player.last_pov = x;
	return (0);
}

int	mouse_release(t_keycode key, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (key == m_right_key)
		g->switches.mouse = false;
	return (0);
}

#ifndef MACOS

static void	_mouse_check(t_game *g)
{
	int	x_mouse;
	int	y_mouse;

	x_mouse = 0;
	y_mouse = 0;
	mlx_mouse_get_pos(g->mlx, g->window, &x_mouse, &y_mouse);
	if ((x_mouse >= WINDOW_X - 50 || y_mouse >= WINDOW_Y - 50 \
	|| x_mouse <= 0 + 50 || y_mouse <= 0 + 50) && g->switches.mouse == false)
		mlx_mouse_move(g->mlx, g->window, WINDOW_X / 2, WINDOW_Y / 2);
}

#else

static void	_mouse_check(t_game *g)
{
	int	x_mouse;
	int	y_mouse;

	x_mouse = 0;
	y_mouse = 0;
	mlx_mouse_get_pos(g->window, &x_mouse, &y_mouse);
	if ((x_mouse >= WINDOW_X - 50 || y_mouse >= WINDOW_Y - 50 \
	|| x_mouse <= 0 + 50 || y_mouse <= 0 + 50) && g->switches.mouse == false)
		mlx_mouse_move(g->window, WINDOW_X / 2, WINDOW_Y / 2);
}

#endif
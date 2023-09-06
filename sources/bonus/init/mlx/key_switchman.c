/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switchman.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:29:37 by twang             #+#    #+#             */
/*   Updated: 2023/09/06 17:11:54 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_view_switch(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

int	key_press(t_keycode key, t_game *g)
{
	if (key == esc_key)
		clean(g);
	if (key == l_key)
		legend_init(g);
	return (0);
}

int	key_switch(t_keycode key, t_game *g)
{
	if (key == w_key)
		w_move(g);
	if (key == a_key)
		a_move(g);
	if (key == s_key)
		s_move(g);
	if (key == d_key)
		d_move(g);
	if (key == up_key)
		w_move(g);
	if (key == down_key)
		s_move(g);
	if (key == left_key || key == right_key)
		_view_switch(key, g);
	return (0);
}

static int	_view_switch(t_keycode key, t_game *g)
{
	if (g->player.diff_pov != 1 && g->player.last_pov > 0)
		g->player.diff_pov = 1;
	if (key == left_key)
		view_left(g);
	if (key == right_key)
		view_right(g);
	return (0);
}

int	mouse_click(t_keycode key, int x, int y,t_game *g)
{
	(void)x;
	(void)y;
	if (key == m_left_key)
		open_door(g);
	return (0);
}

int	mouse_move(int x, int y, t_game *g)
{
	(void)y;
	if (g->player.last_pov > x + 0.5)
	{
		g->player.diff_pov = (g->player.last_pov - x) / 5;
		view_left(g);
	}
	if (g->player.last_pov < x - 0.5)
	{
		g->player.diff_pov = (x - g->player.last_pov) / 5;
		view_right(g);
	}
	g->player.last_pov = x;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switchman.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:29:37 by twang             #+#    #+#             */
/*   Updated: 2023/09/08 14:44:19 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

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
	if (key == space_key)
		open_door(g);
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

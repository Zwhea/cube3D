/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switchman.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:29:37 by twang             #+#    #+#             */
/*   Updated: 2023/09/20 16:07:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_view_switch(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

int	key_switch(t_keycode key, t_game *g)
{
	if (key == esc_key)
		clean(g);
	if (key == l_key)
		legend_init(g);
	if (key == space_key)
		open_door(g);
	if (key == w_key && !g->switches.s_key && !g->switches.down_key)
		g->switches.w_key = true;
	if (key == a_key && !g->switches.d_key)
		g->switches.a_key = true;
	if (key == s_key && !g->switches.w_key && !g->switches.up_key)
		g->switches.s_key = true;
	if (key == d_key && !g->switches.a_key)
		g->switches.d_key = true;
	if (key == up_key && !g->switches.down_key && !g->switches.s_key)
		g->switches.up_key = true;
	if (key == down_key && !g->switches.up_key && !g->switches.w_key)
		g->switches.down_key = true;
	if (key == left_key || key == right_key)
		_view_switch(key, g);
	return (0);
}

int	key_release(t_keycode key, t_game *g)
{
	if (key == w_key && g->switches.w_key)
		g->switches.w_key = false;
	if (key == a_key && g->switches.a_key)
		g->switches.a_key = false;
	if (key == s_key && g->switches.s_key)
		g->switches.s_key = false;
	if (key == d_key && g->switches.d_key)
		g->switches.d_key = false;
	if (key == up_key && g->switches.up_key)
		g->switches.up_key = false;
	if (key == down_key && g->switches.down_key)
		g->switches.down_key = false;
	if (key == left_key && g->switches.left_key)
		g->switches.left_key = false;
	if (key == right_key && g->switches.right_key)
		g->switches.right_key = false;
	return (0);
}

static int	_view_switch(t_keycode key, t_game *g)
{
	if (g->player.diff_pov != 1 && g->player.last_pov > 0)
		g->player.diff_pov = 1;
	if (key == left_key)
		g->switches.left_key = true;
	if (key == right_key)
		g->switches.right_key = true;
	return (0);
}

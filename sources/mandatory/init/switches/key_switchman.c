/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switchman.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:29:37 by twang             #+#    #+#             */
/*   Updated: 2023/10/12 15:43:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_view_switch(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

int	key_manager(t_game *g)
{
	int					i;
	const t_lst_moves	list[] = {{g->switches.w_key, &w_move}, \
									{g->switches.a_key, &a_move}, \
									{g->switches.s_key, &s_move}, \
									{g->switches.d_key, &d_move}, \
									{g->switches.up_key, &w_move}, \
									{g->switches.down_key, &s_move}, \
									{g->switches.left_key, &view_left}, \
									{g->switches.right_key, &view_right}};

	i = -1;
	while (++i < 8)
		if (list[i].switcher)
			list[i].func(g);
	game_display(g);
	return (0);
}

int	key_switch(t_keycode key, t_game *g)
{
	if (key == esc_key)
		clean(g);
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

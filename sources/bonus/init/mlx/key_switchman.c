/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switchman.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:29:37 by twang             #+#    #+#             */
/*   Updated: 2023/09/04 09:36:13 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

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

int	key_press(t_keycode key, t_game *g)
{
	int					i;
	const t_lst_react	react_tab[] = {{esc_key, &clean}, \
										{l_key, &legend_init}, \
										{w_key, &w_move}, \
										{a_key, &a_move}, \
										{s_key, &s_move}, \
										{d_key, &d_move}, \
										{up_key, &w_move}, \
										{down_key, &s_move}, \
										{left_key, &view_left}, \
										{right_key, &view_right}};

	i = -1;
	if (g->player.diff_pov != 1 && g->player.last_pov > 0)
		g->player.diff_pov = 1;
	while (++i < 11)
	{
		if (key == react_tab[i].key)
			return (react_tab[i].func(g));
	}
	return (0);
}

int	key_click(t_keycode key, t_game *g)
{
	int					i;
	const t_lst_react	reacti_tab[] = {{m_left_key, &open_door}};

	i = -1;
	while (++i < 1)
	{
		if (key == reacti_tab[i].key)
			return (reacti_tab[i].func(g));
	}
	return (0);
}

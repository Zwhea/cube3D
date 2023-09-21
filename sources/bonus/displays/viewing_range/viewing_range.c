/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:04 by twang             #+#    #+#             */
/*   Updated: 2023/09/21 10:30:04 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*il faut regarder / proteger dans les cas ou l'angle rendu va depasser
les 360 degres, sauf que il faut le faire avec les radiant je pense et je
ne sais pas faire */

int	view_left(t_game *g)
{
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view -= M_PI * g->player.diff_pov / 48;
	game_display(g);
	return (0);
}

int	view_right(t_game *g)
{
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view += M_PI * g->player.diff_pov / 48;
	game_display(g);
	return (0);
}

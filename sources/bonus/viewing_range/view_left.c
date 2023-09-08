/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:29:44 by twang             #+#    #+#             */
/*   Updated: 2023/09/08 15:13:01 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	view_left(t_game *g)
{
	/*il faut regarder / proteger dans les cas ou l'angle rendu va depasser
	les 360 degres, sauf que il faut le faire avec les radiant je pense et je
	ne sais pas faire */
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view -= M_PI * g->player.diff_pov / 48;
	map_render(g);
	return (0);
}

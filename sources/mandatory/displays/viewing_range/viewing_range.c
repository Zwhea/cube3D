/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:04 by twang             #+#    #+#             */
/*   Updated: 2023/10/03 09:32:35 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	view_left(t_game *g)
{
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view -= M_PI * g->player.diff_pov / 45;
	return (0);
}

int	view_right(t_game *g)
{
	if (g->player.angle_view >= 2 * M_PI)
		g->player.angle_view -= 2 * M_PI;
	else if (g->player.angle_view <= -2 * M_PI)
		g->player.angle_view += 2 * M_PI;
	g->player.angle_view += M_PI * g->player.diff_pov / 45;
	return (0);
}

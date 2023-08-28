/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:40:46 by twang             #+#    #+#             */
/*   Updated: 2023/08/24 12:30:38 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	d_move(t_game *g)
{
	puts(BLUE"je bouge avec d"END);
	g->player.posf.x = g->player.posf.x + 0.10000;
		// printf("x=%f et y=%f\n", g->player.posf.x, g->player.posf.y);
	map_render(g);
	return (0);
}

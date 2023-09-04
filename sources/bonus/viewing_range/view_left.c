/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:29:44 by twang             #+#    #+#             */
/*   Updated: 2023/09/04 13:40:13 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	view_left(t_game *g)
{
	puts("je regarde a gauche");
	g->player.angle_view -= M_PI * g->player.diff_pov / 48;
	map_render(g);
	return (0);
}

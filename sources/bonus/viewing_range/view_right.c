/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:29:44 by twang             #+#    #+#             */
/*   Updated: 2023/08/30 16:19:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	view_right(t_game *g)
{
	puts("je regarde a droite");
	g->player.angle_view += M_PI / 48;
	map_render(g);
	return (0);
}

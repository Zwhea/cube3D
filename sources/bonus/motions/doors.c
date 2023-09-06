/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:39:28 by twang             #+#    #+#             */
/*   Updated: 2023/09/06 16:55:33 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_check_door(t_game *g, int y, int x);

/*----------------------------------------------------------------------------*/

int	open_door(t_game *g)
{
	//vers ou je regarde?
	//si je regarde en haut:
	_check_door(g, g->player.pos.y - 1, g->player.pos.x);
	//si je regarde en bas:
	_check_door(g, g->player.pos.y + 1, g->player.pos.x);
	//si je regarde a gauche:
	_check_door(g, g->player.pos.y, g->player.pos.x - 1);
	//si je regarde a droite:
	_check_door(g, g->player.pos.y, g->player.pos.x + 1);

	return (0);
}

static void	_check_door(t_game *g, int y, int x)
{
	if (g->map.map[y][x] == door)
	{
		puts("ouvrir porte");
		g->map.map[y][x] = o_door;
		map_render(g);
	}
	else if (g->map.map[y][x] == o_door)
	{
		puts("fermer porte");
		g->map.map[y][x] = door;
		map_render(g);
	}
}
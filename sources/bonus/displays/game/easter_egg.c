/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easter_egg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:17:08 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/23 13:17:10 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_print_henri1(t_game *g)
{
	t_vector	pos;

	pos.x = 100;
	while (pos.x < 1820)
	{
		pos.y = 0;
		while (pos.y < 1080)
		{
			pos.y += 100;
			mlx_string_put(g->mlx, g->window, pos.x, pos.y,
				H_ORANGE, "<3 MERCI HENRI GEFFROY <3");
		}
		pos.x += 300;
	}
}

void	thx_henri(t_game *g)
{
	if (g->switches.h_henri == 1)
		_print_henri1(g);
}

void	switch_henri(t_game *g)
{
	if (g->switches.h_henri == 1)
		g->switches.h_henri = 0;
	else if (g->switches.h_henri == 0)
		g->switches.h_henri = 1;
}

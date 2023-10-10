/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:05:36 by twang             #+#    #+#             */
/*   Updated: 2023/10/09 17:16:08 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	textures_checker(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i < 4 && !(g->textures.walls[i].img))
			error_switchman(g, wrong_texture);
		if (i < 3 \
			&& (!(g->sprites.player[i].img) || !(g->sprites.door[i].img)))
			error_switchman(g, wrong_texture);
		i++;
	}
}

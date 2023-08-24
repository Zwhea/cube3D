/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:05:36 by twang             #+#    #+#             */
/*   Updated: 2023/08/23 16:04:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	textures_checker(t_game *g)
{
	int	i;

	i = 0;
	if (g->textures.ceiling == true)
		if(!(g->textures.walls[ceiling_texture].sprite))
			error_switchman(g, wrong_texture);
	if (g->textures.floor == true)
		if(!(g->textures.walls[floor_texture].sprite))
			error_switchman(g, wrong_texture);
	while (i < 3)
	{
		if (i < 3 && !(g->textures.walls[i].sprite))
			error_switchman(g, wrong_texture);
		i++;
	}
}

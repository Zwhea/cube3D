/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:28 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 15:35:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	textures_checker(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i < 3 && !(g->textures.walls[i].img))
			error_switchman(g, wrong_texture);
		i++;
	}
}

void	color_checker(t_game *g)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (i < 2 && !(g->color[i].get))
			error_switchman(g, wrong_color);
		i++;
	}
}

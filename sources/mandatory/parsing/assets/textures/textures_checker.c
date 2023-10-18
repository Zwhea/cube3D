/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:28 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/18 13:16:08 by aascedu          ###   ########.fr       */
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

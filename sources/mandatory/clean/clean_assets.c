/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:54 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/20 15:25:22 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_textures(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i < 4 && (g->textures.walls[i].img))
			mlx_destroy_image(g->mlx, g->textures.walls[i].img);
	}
}

void	clean_maps(t_game *g)
{
	if (g->map.map)
		free_split(g->map.map, g->map.size.y);
	if (g->map.line_len)
		free(g->map.line_len);
	return ;
}

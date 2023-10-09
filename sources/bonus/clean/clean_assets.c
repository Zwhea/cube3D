/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:54 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/09 17:14:45 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	close_n_free(t_game *g, bool is_error)
{
	if (g->file.fd)
		close(g->file.fd);
	if (is_error == true)
		return (-1);
	return (0);
}

void	clean_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i < 4 && (g->textures.walls[i].img))
			mlx_destroy_image(g->mlx, g->textures.walls[i].img);
		if (i < 3 && (g->sprites.player[i].img))
			mlx_destroy_image(g->mlx, g->sprites.player[i].img);
		if (i < 3 && (g->sprites.door[i].img))
			mlx_destroy_image(g->mlx, g->sprites.door[i].img);
		i++;
	}
}

void	clean_maps(t_game *g)
{
	if (g->map.map)
		free_split(g->map.map, g->map.size.y);
	free(g->map.line_len);
	return ;
}

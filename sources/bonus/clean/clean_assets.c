/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:54 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/04 15:43:25 by twang            ###   ########.fr       */
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
	if (g->textures.walls[ceiling_texture].img)
		mlx_destroy_image(g->mlx, g->textures.walls[ceiling_texture].img);
	if (g->textures.walls[floor_texture].img)
		mlx_destroy_image(g->mlx, g->textures.walls[floor_texture].img);
	while (i < 4)
	{
		if (i < 4 && (g->textures.walls[i].img))
			mlx_destroy_image(g->mlx, g->textures.walls[i].img);
		if (i < 3 && (g->animations.player[i].img))
			mlx_destroy_image(g->mlx, g->animations.player[i].img);
		if (i < 3 && (g->animations.door[i].img))
			mlx_destroy_image(g->mlx, g->animations.door[i].img);
		i++;
	}
}

void	clean_maps(t_game *g)
{
	if (g->map.map)
		free_split(g->map.map, g->map.size.y);
	if (g->map.mini_map)
		free_split(g->map.mini_map, g->map.size.y + 11);
	free(g->map.line_len);
	return ;
}

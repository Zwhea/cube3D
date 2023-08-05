/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:43:55 by twang             #+#    #+#             */
/*   Updated: 2023/08/05 13:38:18 by twang            ###   ########.fr       */
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
	while (i < 6)
	{
		if (i < 6 && (g->textures.walls[i].sprite))
			mlx_destroy_image(g->mlx, g->textures.walls[i].sprite);
		i++;
	}
}

void	clean_map(t_game *g)
{
	free_split(g->map.map, g->map.size.y);
	exit(0);
}

int	clean(t_game *g)
{
	clean_textures(g);
	if (g->map.map)
		clean_map(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
}

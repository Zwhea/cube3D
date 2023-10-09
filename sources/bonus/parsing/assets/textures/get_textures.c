/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:16 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/04 13:55:50 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_north_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.walls[north_texture].img)
	{
		free(line);
		error_switchman(g, wrong_textures);
	}
	while (line[i] && ft_strchr(TEXTURE_NORTH, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	init_textures(g, s, north_texture);
	return ;
}

void	handle_south_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.walls[south_texture].img)
	{
		free(line);
		error_switchman(g, wrong_textures);
	}
	while (line[i] && ft_strchr(TEXTURE_SOUTH, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	init_textures(g, s, south_texture);
	return ;
}

void	handle_west_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.walls[west_texture].img)
	{
		free(line);
		error_switchman(g, wrong_textures);
	}
	while (line[i] && ft_strchr(TEXTURE_WEST, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	init_textures(g, s, west_texture);
	return ;
}

void	handle_east_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.walls[east_texture].img)
	{
		free(line);
		error_switchman(g, wrong_textures);
	}
	while (line[i] && ft_strchr(TEXTURE_EAST, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	init_textures(g, s, east_texture);
	return ;
}

void	init_textures(t_game *g, char *s, int id)
{
	g->textures.walls[id].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[id].width, \
									&g->textures.walls[id].height);
	// IL FAUT PROTEGER LES TEXTURES (NOM DE TEXTURES)
	g->textures.walls[id].addr = mlx_get_data_addr(g->textures.walls[id].img, \
										&g->textures.walls[id].bits_per_pixel, \
										&g->textures.walls[id].line_length, \
										&g->textures.walls[id].endian);
	// PROTEGER MLX_GET_DATA_ADDR
}

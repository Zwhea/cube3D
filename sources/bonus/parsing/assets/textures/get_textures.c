/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:16 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/03 15:59:03 by twang            ###   ########.fr       */
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
	g->textures.walls[north_texture].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[north_texture].width, &g->textures.walls[north_texture].height);
	g->textures.walls[north_texture].addr = mlx_get_data_addr(g->textures.walls[north_texture].img, &g->textures.walls[north_texture].bits_per_pixel, &g->textures.walls[north_texture].line_length, &g->textures.walls[north_texture].endian);
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
	g->textures.walls[south_texture].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[south_texture].width, &g->textures.walls[south_texture].height);
	g->textures.walls[south_texture].addr = mlx_get_data_addr(g->textures.walls[south_texture].img, &g->textures.walls[south_texture].bits_per_pixel, &g->textures.walls[south_texture].line_length, &g->textures.walls[south_texture].endian);
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
	g->textures.walls[west_texture].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[west_texture].width, &g->textures.walls[west_texture].height);
	g->textures.walls[west_texture].addr = mlx_get_data_addr(g->textures.walls[west_texture].img, &g->textures.walls[west_texture].bits_per_pixel, &g->textures.walls[west_texture].line_length, &g->textures.walls[west_texture].endian);
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
	g->textures.walls[east_texture].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[east_texture].width, &g->textures.walls[east_texture].height);
	g->textures.walls[east_texture].addr = mlx_get_data_addr(g->textures.walls[east_texture].img, &g->textures.walls[east_texture].bits_per_pixel, &g->textures.walls[east_texture].line_length, &g->textures.walls[east_texture].endian);
	return ;
}

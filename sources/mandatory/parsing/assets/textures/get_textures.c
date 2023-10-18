/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:16 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/10 08:53:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	if (init_textures(g, s, north_texture))
	{
		free(line);
		error_switchman(g, wrong_texture);
	}
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
	if (init_textures(g, s, south_texture))
	{
		free(line);
		error_switchman(g, wrong_texture);
	}
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
	if (init_textures(g, s, west_texture))
	{
		free(line);
		error_switchman(g, wrong_texture);
	}
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
	if (init_textures(g, s, east_texture))
	{
		free(line);
		error_switchman(g, wrong_texture);
	}
	return ;
}

int	init_textures(t_game *g, char *s, int id)
{
	g->textures.walls[id].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[id].width, \
									&g->textures.walls[id].height);
	if (!g->textures.walls[id].img)
		return (1);
	g->textures.walls[id].addr = mlx_get_data_addr(g->textures.walls[id].img, \
										&g->textures.walls[id].bits_per_pixel, \
										&g->textures.walls[id].line_length, \
										&g->textures.walls[id].endian);
	if (!g->textures.walls[id].addr)
		return (1);
	return (0);
}

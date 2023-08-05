/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:16 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/05 12:05:25 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_north_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_NORTH, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	printf("%s\n", s);
	g->textures.walls[north_texture].sprite = mlx_xpm_to_image(g->mlx, &s, &g->textures.size.x, &g->textures.size.y);
	return ;
}

void	handle_south_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_SOUTH, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	printf("%s\n", s);
	g->textures.walls[south_texture].sprite = mlx_xpm_to_image(g->mlx, &s, &g->textures.size.x, &g->textures.size.y);
	return ;
}

void	handle_west_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_WEST, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	printf("%s\n", s);
	g->textures.walls[west_texture].sprite = mlx_xpm_to_image(g->mlx, &s, &g->textures.size.x, &g->textures.size.y);
	return ;
}

void	handle_east_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_EAST, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	printf("%s\n", s);
	g->textures.walls[east_texture].sprite = mlx_xpm_to_image(g->mlx, &s, &g->textures.size.x, &g->textures.size.y);
	return ;
}

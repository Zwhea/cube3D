/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:16 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 17:38:57 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	get_north_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_NORTH, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_south_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_SOUTH, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_west_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_WEST, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_east_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_EAST, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

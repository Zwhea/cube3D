/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:16 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/04 15:04:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_north_texture(t_game *g, char *line)
{
	(void)g;
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
	printf(GREEN"--%s--\n"END, s);
	return ;
}

void	handle_south_texture(t_game *g, char *line)
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

void	handle_west_texture(t_game *g, char *line)
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

void	handle_east_texture(t_game *g, char *line)
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

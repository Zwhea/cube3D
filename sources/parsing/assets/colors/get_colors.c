/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:37:45 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/03 12:01:45 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_ceiling_color(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(COLOR_CEILING, line[i]))
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

void	handle_floor_color(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(COLOR_FLOOR, line[i]))
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

void	handle_no_asset(t_game *g, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (!line[i])
		return ;
	else
		error_switchman(g, wrong_asset);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:13:02 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/10 12:03:08 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	colors_checker(t_game *g, char *line)
{
	int	coma_nb;
	int	i;

	coma_nb = 0;
	i = -1;
	while (line[++i] && ft_strchr(COLOR_CHARSET, line[i]))
	{
		if (line[i] == ',')
			coma_nb++;
	}
	if (line[i] != '\0' || coma_nb != 2)
		error_switchman(g, wrong_color);
}

void	extract_colors(t_game *g, char *line, t_keyassets color_id)
{
	char	**color;
	int		id;

	color = (char **)ft_calloc(4, sizeof(char *));
	color = ft_split(line, ',');
	if (!color)
		puts("cheh");
	id = 0;
	while (color[id])
	{
		extract_nbrs(g, color_id, id, color[id]);
		id++;
	}
	free_split(color, 4);
}

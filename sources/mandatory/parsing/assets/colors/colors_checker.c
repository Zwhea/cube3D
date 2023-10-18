/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:13:02 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/21 13:56:10 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	colors_checker(t_game *g, char *line)
{
	int	coma_nb;
	int	i;

	(void)g;
	coma_nb = 0;
	i = -1;
	while (line[++i] && ft_strchr(COLOR_CHARSET, line[i]))
	{
		if (line[i] == ',')
			coma_nb++;
	}
	if (line[i] != '\0' || coma_nb != 2)
		return (1);
	return (0);
}

void	extract_colors(t_game *g, char *line, t_keyassets color_id)
{
	char	**color;
	int		id;

	color = ft_split(line, ',');
	if (!color)
		clean(g);
	id = 0;
	while (color[id])
	{
		extrct_nbrs(g, color_id, id, color[id]);
		id++;
	}
	free_split(color, 4);
}

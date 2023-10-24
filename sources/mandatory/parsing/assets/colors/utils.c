/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/24 09:48:15 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_extract_ceiling_color(t_game *g, int i, char *line);
static int	_extract_floor_color(t_game *g, int i, char *line);
static int	_check_nbr(char *str);

/*----------------------------------------------------------------------------*/

int	extrct_nbrs(t_game *g, t_keyassets color_id, int i, char *line)
{
	if (color_id == ceiling_color)
	{
		if (_extract_ceiling_color(g, i, line))
			return (1);
	}
	else if (color_id == floor_color)
	{
		if (_extract_floor_color(g, i, line))
			return (1);
	}
	return (0);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	_check_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str && str[i])
	{
		if (ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	_extract_ceiling_color(t_game *g, int i, char *line)
{
	if (_check_nbr(line))
		return (1);
	if (i == 0)
		g->color[0].r = ft_atoi(line);
	else if (i == 1)
		g->color[0].g = ft_atoi(line);
	else
		g->color[0].b = ft_atoi(line);
	return (0);
}

static int	_extract_floor_color(t_game *g, int i, char *line)
{
	if (_check_nbr(line))
		return (1);
	if (i == 0)
		g->color[1].r = ft_atoi(line);
	else if (i == 1)
		g->color[1].g = ft_atoi(line);
	else
		g->color[1].b = ft_atoi(line);
	return (0);
}

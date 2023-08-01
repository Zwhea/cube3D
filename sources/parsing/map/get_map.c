/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:58:49 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 19:31:55 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static size_t	_get_map_size(t_game *g, int fd);

/*----------------------------------------------------------------------------*/

void	get_map(t_game *g, int fd)
{
	g->map.map = (char **)ft_calloc(_get_map_size(g, fd), sizeof(char *));
	free(g->map.map);
}

static size_t	_get_map_size(t_game *g, int fd)
{
	char	*line;

	line = get_next_line(fd);
	g->map.size_y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		g->map.size_y++;
	}
	if (line)
		free(line);
	// printf(GREEN"size : %d\n"END, g->map.size_y);
	return (g->map.size_y);
}

void	ft_memdel(void **p)
{
	if (p == NULL || *p == NULL)
		return ;
	free(*p);
	*p = NULL;
}

void	**ft_realloc_array(void **p, int height)
{
	void	**pt;
	int		old_height;
	int		i;
	
	pt = NULL;
	old_height = ft_arraylen(p);
	i = 0;
	if (height > 0 && old_height < height)
	{
		pt = (void **)ft_calloc(height, sizeof(void *));
		if (p != NULL && pt != NULL)
		{
			while (i < old_height)
			{
				pt[i] = (void *)ft_calloc(ft_strlen(p[i]), sizeof(void));
				ft_memcpy(pt[i], p[i], ft_strlen(p[i]));
				ft_memdel(&p[i]);
				i++;
			}
			ft_memdel(&p);
		}
	}
	return (pt);
}

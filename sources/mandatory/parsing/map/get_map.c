/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:58:49 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/12 15:41:20 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(t_game *g, int fd, int start_map)
{
	int		i;
	char	*tmp_line;

	i = 0;
	tmp_line = NULL;
	g->map.map = (char **)ft_calloc(set_map_height(g, fd) + 1, sizeof(char *));
	if (!g->map.map)
		clean(g);
	g->map.line_len = (int *)ft_calloc(g->map.size.y + 1, sizeof(int));
	if (!g->map.line_len)
		clean(g);
	fd = open_file(g->file.file);
	while (start_map-- > 0)
	{
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	while (tmp_line)
	{
		g->map.line_len[i] = ft_strlen_char(tmp_line, '\n');
		g->map.map[i++] = tmp_line;
		tmp_line = get_next_line(fd);
	}
	g->map.map[i] = NULL;
	close(fd);
}

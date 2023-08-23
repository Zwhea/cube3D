/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:49:25 by twang             #+#    #+#             */
/*   Updated: 2023/08/23 12:46:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

static char	*_ft_fill(t_game *g, char *s);
static char	*_ft_dup_fill(t_game *g, char *src, char *dst);

void	get_mini_map(t_game *g)
{
	int	i;
	int	j;

	g->map.mini_map = (char **)ft_calloc(g->map.size.y + 11, sizeof(char *));
	if (!g->map.mini_map)
		return ;
	i = -1;
	j = -1;
	while (++j < 5)
		g->map.mini_map[j] = _ft_fill(g, g->map.mini_map[j]);
	while (g->map.map[++i])
	{
		g->map.mini_map[j] = _ft_dup_fill(g, g->map.map[i], g->map.mini_map[j]);
		j++;
	}
	while (j < g->map.size.y + 10)
	{
		g->map.mini_map[j] = _ft_fill(g, g->map.mini_map[j]);
		j++;
	}
}

static char	*_ft_fill(t_game *g, char *s)
{
	int	i;
	
	s = (char *)ft_calloc(g->map.size.x + 12, sizeof(char));
	if (!s)
		return (NULL);
	i = -1;
	while (++i < g->map.size.x + 10)
		s[i] = bloup;
	s[i] = '\n';
	return (s);
}

static char	*_ft_dup_fill(t_game *g, char *src, char *dst)
{
	int	i;
	int	j;
	
	dst = (char *)ft_calloc(g->map.size.x + 12, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < 5)
		dst[j] = bloup;
	while (src[i])
		dst[j++] = src[i++];
	j--;
	while (j < g->map.size.x + 10)
		dst[j++] = bloup;
	dst[j] = '\n';
	return (dst);
}

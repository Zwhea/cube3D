/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/31 13:11:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_file(t_game *g, char *file);
static char	*_extract_file(t_game *g, char *file);
static int	_check_file_content(t_game *g);

/*----------------------------------------------------------------------------*/

char	**get_file(t_game *g, char *file)
{
	if (_check_file(g, file) == -1)
	{
		error_switchman(g, bad_file);
		return (NULL);
	}
	if (!(_extract_file(g, file)))
	{
		close(g->file.file_fd);
		error_switchman(g, extract_fail);
		return (NULL);
	}
	_check_file_content(g);
	return (g->file.split_file);
}

static int	_check_file(t_game *g, char *file)
{
	if (check_extension(file, ".cub") != true)
		return (-1);
	g->file.file_fd = open_file(file);
	return (g->file.file_fd);
}

static char	*_extract_file(t_game *g, char *original)
{
	int		i;
	int		bytes_read;
	char	c;

	g->file.origin_file = (char *)ft_calloc(get_alloc_size(original) + 1, sizeof(char));
	if (!g->file.origin_file)
		return (NULL);
	i = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(g->file.file_fd, &c, 1);
		if (bytes_read == -1)
			read_error(g->file.file_fd);
		if (bytes_read != 0)
			g->file.origin_file[i] = c;
		i++;
	}
	close(g->file.file_fd);
	return (g->file.origin_file);
}

static int	_check_file_content(t_game *g)
{
	g->file.split_file = ft_split(g->file.origin_file, '\n');
	if (!g->file.split_file)
		return (close_n_free(g, true));
	while (g->file.split_file[g->file.size_file])
		g->file.size_file++;
	ft_print_split(g->file.split_file);
	return (0);
}

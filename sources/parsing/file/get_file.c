/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/27 18:30:10 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_file(char *file);
static char	*_extract_file(char *file);
static int	_check_file_content(t_game *g, char *file);

/*----------------------------------------------------------------------------*/

char	*get_file(t_game *g, char *file)
{
	char	*new_file;

	if (_check_file(file) == -1)
	{
		error_switchman(g, bad_file);
		return (NULL);
	}
	new_file = _extract_file(file);
	if (!(new_file))
	{
		error_switchman(g, extract_fail);
		free(new_file);
		return (NULL);
	}
	_check_file_content(g, new_file);
	return (new_file);
}

static int	_check_file(char *file)
{
	int	map_fd;

	map_fd = 0;
	if (check_extension(file, ".cub") != true)
		return (-1);
	map_fd = open_file(file);
	return (map_fd);
}

static char	*_extract_file(char *original)
{
	int		i;
	int		file_fd;
	int		bytes_read;
	char	*file;
	char	c;

	file = (char *)ft_calloc(get_alloc_size(original) + 1, sizeof(char));
	if (!file)
		return (NULL);
	file_fd = open_file(original);
	i = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(file_fd, &c, 1);
		if (bytes_read == -1)
			read_error(file_fd);
		if (bytes_read != 0)
			file[i] = c;
		i++;
	}
	close(file_fd);
	return (file);
}

static int	_check_file_content(t_game *g, char *file)
{
	(void)g;
	int	i;
	
	i = 0;
	while (file[i])
	{
		i++;
	}
	puts("je dois checker que le fichier commence bien par soit des textures soit des colors");
	return (0);
}

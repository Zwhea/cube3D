/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:42:06 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/30 15:05:24 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	read_error(int fd)
{
	perror("read");
	close(fd);
	exit(-2);
}

int	get_alloc_size(const char *file)
{
	int		fd;
	int		bytes_read;
	int		size;
	char	c;

	fd = open_file(file);
	bytes_read = 1;
	size = 0;
	c = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read == -1)
			read_error(fd);
		size++;
	}
	close(fd);
	return (size);
}

int	is_north_texture(int start, char *s)
{
	if (ft_strncmp(&s[start], "NO", 2) == 0)
		return (1);
	return (0);
}

int	is_south_texture(int start, char *s)
{
	if (ft_strncmp(&s[start], "SO", 2) == 0)
		return (1);
	return (0);
}

int	is_west_texture(int start, char *s)
{
	if (ft_strncmp(&s[start], "WE", 2) == 0)
		return (1);
	return (0);
}

int	is_east_texture(int start, char *s)
{
	if (ft_strncmp(&s[start], "EA", 2) == 0)
		return (1);
	return (0);
}
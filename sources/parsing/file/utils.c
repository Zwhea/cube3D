/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:42:06 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/25 12:57:42 by wangthea         ###   ########.fr       */
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

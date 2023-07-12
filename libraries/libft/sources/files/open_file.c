/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:48:21 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 11:38:50 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY, 0644);
	if (fd != -1)
	{
		ft_dprintf(2, RED"Error\n"END);
		ft_dprintf(2, YELLOW"warning: "END);
		ft_dprintf(2, "the file shouldn't be a directory\n");
		close(fd);
		return (-1);
	}
	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, RED"Error\n"END);
		perror("open");
		close(fd);
		return (-1);
	}
	return (fd);
}

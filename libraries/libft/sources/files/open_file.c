/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:48:21 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 10:39:18 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY, 0644);
	if (fd != -1)
	{
		close(fd);
		close_program("the file shouldn't be a directory");
	}
	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		close(fd);
	return (fd);
}

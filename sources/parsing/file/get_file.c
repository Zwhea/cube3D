/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/24 17:26:35 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_file(char *file);
static int	_extract_file(t_game *g, char *file);

/*----------------------------------------------------------------------------*/

int	get_file(t_game *g, char *file)
{
	if (_check_file(file) == -1)
	{
		error_switchman(g, bad_file);
		return (-1);
	}
	if (_extract_file(g, file) == -1)
	{
		error_switchman(g, extract_fail);
		return (-1);
	}
	return (0);
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

static int	_extract_file(t_game *g, char *file)
{
	(void)g;
	(void)file;
	puts("on va jusqu'ici");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/21 15:52:17 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	check_map_file(char *file)
{
	int	map_fd;
	
	map_fd = 0;
	if (check_extension(file, ".cub") != true)
		return (-1);
	map_fd = open_file(file);
	return (map_fd);
}

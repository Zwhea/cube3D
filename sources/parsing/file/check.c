/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:08:11 by twang             #+#    #+#             */
/*   Updated: 2023/08/02 19:10:22 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	check_file(t_game *game, char *file)
{
	if (check_extension(file, ".cub") != true)
		return (-1);
	g->file.fd = open_file(file);
	if (g->file.fd < 0)
		return (-1);
	g->file.file = file;
	return (fd);
}

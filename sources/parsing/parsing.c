/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/21 15:52:57 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	parsing(t_game *g, int ac, char **av)
{
	if (ac > 2)
		error_switchman(g, too_much_args);
	if (check_map_file(av[1]) == -1)
	{
		error_switchman(g, bad_file);
		return (-1);
	}
	printf("%s", av[1]);
	printf("i need to :\n\t- open the map\n\t- check the file & its extensions\
			\n\t- recup the map in the struct\n\t- start to parse it\n");
	return (0);
}

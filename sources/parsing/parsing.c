/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/24 12:12:40 by wangthea         ###   ########.fr       */
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
	if (get_map(g, av[1]) == -1)
	{
		error_switchman(g, no_map);
		return (-1);
	}
	/*
	if (check_map(g) == -1)
	{
		error_switchman(g, bad_map);
		return (-1);
	}
	*/
	return (0);
}

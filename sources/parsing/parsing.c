/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/24 16:54:33 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	parsing(t_game *g, int ac, char **av)
{
	if (ac > 2)
		error_switchman(g, too_much_args);
	if (get_file(g, av[1]) == -1)
		return (-1);
	return (0);
}

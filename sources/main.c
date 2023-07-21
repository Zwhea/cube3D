/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:11:10 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/21 15:22:40 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
// #include "cub3D_arthur.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		if (parsing(&g, ac, av))
			return (-1);
	}
	return (0);
}

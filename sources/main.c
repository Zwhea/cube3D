/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:11:10 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/20 21:40:43 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
// #include "cub3D_arthur.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac <= 1)
		error_switchman(&g, no_args);
	if (ac == 2)
	{
		if (parsing(&g, av[1]))
			return (-1);
		printf("%s %s\n", av[0], av[1]);
	}
	else
		error_switchman(&g, too_much_args);
	return (0);
}

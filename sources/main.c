/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:11:10 by wangthea          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/26 11:16:27 by twang            ###   ########.fr       */
=======
/*   Updated: 2023/07/21 15:22:40 by wangthea         ###   ########.fr       */
>>>>>>> a2caee9d5bc7f5142f867a31d87fd787d319ff6f
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
// #include "cub3D_arthur.h"

int	main(int ac, char **av)
{
<<<<<<< HEAD
	if (ac == 1)
	{
		print_msg(2, ERROR, "wrong number arguments");
		
		print_msg(2, WARNING, "please input a map");
		print_msg(2, USAGE, "./cub3D map.cub");
	}
	if (ac == 2)
	{
		printf("%s %s\n", av[0], av[1]);
	}
=======
	t_game	g;

	if (ac <= 1)
		error_switchman(&g, no_args);
>>>>>>> a2caee9d5bc7f5142f867a31d87fd787d319ff6f
	else
	{
		if (parsing(&g, ac, av))
			return (-1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:11:10 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/26 11:16:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
// #include "cub3D_arthur.h"

int	main(int ac, char **av)
{
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
	else
	{
		print_msg(2, ERROR, "wrong number arguments");
		print_msg(2, WARNING, "please bear in mind that this program will only be using the first argument as map");
	}
	return (0);
}

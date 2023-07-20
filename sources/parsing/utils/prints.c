/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:11:24 by twang             #+#    #+#             */
/*   Updated: 2023/07/20 21:37:25 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	print_error(bool warn, char *msg)
{
	ft_dprintf(2, GREEN BOLD"cub3d: "END);
	if (warn == true)
		warning();
	else
		error();
	usage();
	ft_dprintf(2, "%s\n", msg);
}

void	error(void)
{
	ft_dprintf(2, RED"error: "END);
}

void	warning(void)
{
	ft_dprintf(2, YELLOW"warning: "END);
}

void	usage(void)
{
	ft_dprintf(2, GREEN"usage: ./cub3D map.cub\n"END);
}

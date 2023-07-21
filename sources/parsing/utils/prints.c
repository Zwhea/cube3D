/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:11:24 by twang             #+#    #+#             */
/*   Updated: 2023/07/21 15:29:45 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	print_error(t_game *g, bool warn, bool how_to, char *msg)
{
	if (warn == false)
		is_this_first_error(g);
	else
		warning();
	ft_dprintf(2, "%s", msg);
	if (how_to == true)
		usage();
}

void	error(void)
{
	ft_dprintf(2, RED"error: "END);
}

void	warning(void)
{
	ft_dprintf(2, GREEN BOLD"cub3d: "END);
	ft_dprintf(2, YELLOW"warning: "END);
}

void	usage(void)
{
	ft_dprintf(2, GREEN"\nusage: ./cub3D <map.cub>\n"END);
}

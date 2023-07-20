/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:11:24 by twang             #+#    #+#             */
/*   Updated: 2023/07/20 15:48:22 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	print_msg(int fd, char *type, char *msg)
{
	ft_dprintf(fd, GREEN BOLD"cub3d: "END);
	if (!(ft_strcmp(type, WARNING)))
		ft_dprintf(fd, YELLOW"warning: "END);
	else
		ft_dprintf(fd, RED"error: "END);
	ft_dprintf(fd, "%s\n", msg);
}

void	error_switchman(int error_key)
{
	
}
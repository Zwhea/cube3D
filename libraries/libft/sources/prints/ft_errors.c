/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:28:31 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/23 12:11:46 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	close_program(char *msg)
{
	program();
	error();
	ft_dprintf(2, "\t%s\n", msg);
	usage();
	exit (-1);
}

void	program(void)
{
	ft_dprintf(2, GREEN BOLD"cub3D:"END);
}

void	error(void)
{
	ft_dprintf(2, RED"\terror: "END);
}

void	warning(void)
{
	ft_dprintf(2, YELLOW"\twarning: "END);
}

void	usage(void)
{
	ft_dprintf(2, GREEN"\n\tusage: "END);
	ft_dprintf(2, "./cub3D <map.cub>\n");
}

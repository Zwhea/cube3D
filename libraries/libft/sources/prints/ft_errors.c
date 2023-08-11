/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:28:31 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 14:06:58 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	close_program(char *msg)
{
	error();
	ft_dprintf(2, "%s\n", msg);
	usage();
	exit (-1);
}

void	program(void)
{
	ft_dprintf(2, GREEN BOLD"cub3D:"END);
}

void	error(void)
{
	ft_dprintf(2, RED"Error\n"END);
	ft_dprintf(2, GREEN"type :\t- "END);
}

void	warning(void)
{
	ft_dprintf(2, YELLOW"warning:"END);
}

void	usage(void)
{
	ft_dprintf(2, GREEN"usage:\t- "END);
	ft_dprintf(2, "./cub3D <map.cub>\n");
	ft_dprintf(2, GREEN"tips :\t- "END);
	ft_dprintf(2, "check the name & rights of given file\n");
}

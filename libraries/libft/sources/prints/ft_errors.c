/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:28:31 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/05 18:27:15 by twang            ###   ########.fr       */
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
	ft_dprintf(2, YELLOW"\twarning:"END);
}

void	usage(void)
{
	ft_dprintf(2, GREEN"\tusage:\t"END);
	ft_dprintf(2, "- ./cub3D <map.cub>\n");
	ft_dprintf(2, GREEN"\ttips:\t"END);
	ft_dprintf(2, "- check the name & rights of given file\n");
}

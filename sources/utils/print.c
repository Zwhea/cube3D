/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:12:24 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 17:16:55 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_dprintf(2, RED"Error\n"END);
}

void	warn(char *message)
{
	ft_dprintf(2, YELLOW"warning:"END" %s\n", message);
}

void	usage(void)
{
	ft_dprintf(2, BLUE"usage:"END" ./cub3D \"file_name.cub\"\n");
}

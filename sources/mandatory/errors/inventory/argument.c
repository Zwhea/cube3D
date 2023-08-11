/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:55:13 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 10:28:50 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_no_arg(t_game *g)
{
	ft_error(g, false, true, NO_ARG);
}

void	_much_arg(t_game *g)
{
	ft_error(g, true, false, MUCH_ARG);
}

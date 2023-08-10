/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:55:13 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 19:12:55 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_no_arg(t_game *g)
{
	ft_error(g, false, true, NO_ARG);
}

void	_much_arg(t_game *g)
{
	ft_error(g, true, true, MUCH_ARG);
}

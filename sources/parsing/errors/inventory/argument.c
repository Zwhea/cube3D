/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:55:13 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/25 11:56:32 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	no_arg(t_game *g)
{
	ft_error(g, false, true, NO_ARG);
}

void	too_much_arg(t_game *g)
{
	ft_error(g, true, true, TOO_MUCH_ARG);
}

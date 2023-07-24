/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:06:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/24 10:46:52 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	error_switchman(t_game *g, t_error_keys error_key)
{
	const t_errors_ft	error_tab[] = {&no_arg, &too_much_arg, &no_file};

	(*error_tab[error_key])(g);
}

void	no_arg(t_game *g)
{
	ft_error(g, true, false, true, NO_ARG);
}

void	too_much_arg(t_game *g)
{
	ft_error(g, false, true, true, TOO_MUCH_ARG);
}

void	no_file(t_game *g)
{
	ft_error(g, true, false, true, NO_FILE);
}

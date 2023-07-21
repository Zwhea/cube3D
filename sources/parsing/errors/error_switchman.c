/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:06:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/21 14:52:23 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	error_switchman(t_game *g, t_error_keys error_key)
{
	const t_errors_ft	error_tab[] = {&no_arg, &too_much_arg, NULL};

	(*error_tab[error_key])(g);
}

void	no_arg(t_game *g)
{
	print_error(g, false, true, "program needs a map you fool !!!");
	exit (-1);
}

void	too_much_arg(t_game *g)
{
	print_error(g, true, true, "program will only look at the first argument, you are welcome to find a way to deal with it.");
}

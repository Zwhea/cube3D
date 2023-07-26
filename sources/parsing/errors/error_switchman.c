/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:06:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/25 13:00:01 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	error_switchman(t_game *g, t_error_keys error_key)
{
	const t_errors_ft	error_tab[] = {&no_arg, &too_much_arg, &no_file};

	(*error_tab[error_key])(g);
}

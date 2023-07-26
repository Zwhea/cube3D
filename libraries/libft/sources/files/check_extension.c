/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:49:35 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/25 11:54:14 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	check_extension(char *file, char *extension)
{
	int	file_length;
	int	ext_length;
	int	total_lenght;

	file_length = ft_strlen(file);
	ext_length = ft_strlen(extension);
	total_lenght = ft_strlen(file) - ft_strlen(extension) - 1;
	if (ft_strnstr_m(file, extension, file_length))
		close_program("wrong file extension");
	if (file_length <= ext_length)
		close_program("it works better when your map has a name");
	if (file[total_lenght] == '/')
		close_program("the file name is invalid");
	return (true);
}

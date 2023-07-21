/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:39:10 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/21 15:45:45 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- defines ---------------------------------------------------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*---- prototypes ------------------------------------------------------------*/

bool	check_extension(char *file, char *extension);

int		close_file(int file);
int		open_file(const char *file);
char	*get_next_line(int fd);

char	*get_strchr(char *s, int c);
char	*get_calloc(size_t count, size_t size);
char	*get_strjoin(char *s1, char *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:39:10 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 14:11:31 by wangthea         ###   ########.fr       */
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

int		close_file(int file);
int		open_file(const char *file);
char	*get_next_line(int fd);

char	*get_strchr(char *s, int c);
char	*get_calloc(size_t count, size_t size);
char	*get_strjoin(char *s1, char *s2);

#endif
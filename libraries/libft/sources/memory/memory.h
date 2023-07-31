/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:13:47 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/31 09:35:29 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- prototypes ------------------------------------------------------------*/

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*free_split(char **s, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);

#endif
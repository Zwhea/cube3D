/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:15:09 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 14:33:21 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTS_H
# define PRINTS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- defines ---------------------------------------------------------------*/

# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

/*---- prototypes ------------------------------------------------------------*/

int		ft_dprintf(int fd, const char *str, ...);
int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
size_t	ft_putchar_fd(int c, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_base(unsigned long nbr, char *base, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putnbr_unsigned_fd(unsigned int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
void	ft_putdebug(int line, char *file);
void	ft_putidebug(int x, int line, char *file);
void	ft_putsdebug(const char *x, int line, char *file);

#endif
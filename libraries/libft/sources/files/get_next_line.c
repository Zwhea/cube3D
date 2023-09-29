/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:27:25 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/29 10:20:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_index_nl(char *buff)
{
	int	i;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
	}
	return (i);
}

char	*ft_strjoin_free(char *line, char *temp)
{
	char	*result;
	int		line_len;
	int		temp_len;
	int		i;

	line_len = ft_strlen(line);
	temp_len = ft_strlen(temp);
	result = (char *)malloc(sizeof(char) * (line_len + temp_len + 1));
	if (!result)
	{
		free(line);
		free(temp);
		return (NULL);
	}
	i = -1;
	while (line[++i])
		result[i] = line[i];
	i = -1;
	while (temp[++i])
		result[line_len + i] = temp[i];
	result[line_len + temp_len] = '\0';
	free(line);
	free(temp);
	return (result);
}

char	*add_buffer(char *line, char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_index_nl(buff);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	j = -1;
	while (++j < i)
		temp[j] = buff[j];
	temp[j] = '\0';
	temp = ft_strjoin_free(line, temp);
	ft_memmove(buff, buff + i, BUFFER_SIZE - i);
	ft_bzero(buff + (BUFFER_SIZE - i), ft_strlen(buff + (BUFFER_SIZE - i)));
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			byte_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_bzero(buff, BUFFER_SIZE + 1), NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = 0;
	byte_read = 1;
	if (!buff[0])
		byte_read = read(fd, buff, BUFFER_SIZE);
	if (byte_read <= 0)
		return (free(line), NULL);
	while (byte_read)
	{
		if (ft_newline(buff))
			return (add_buffer(line, buff));
		line = add_buffer(line, buff);
		byte_read = read(fd, buff, BUFFER_SIZE);
	}
	return (add_buffer(line, buff));
}

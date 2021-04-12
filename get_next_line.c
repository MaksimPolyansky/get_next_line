/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:20:18 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/14 13:22:48 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		my_free(char **s)
{
	if (*s)
		free(*s);
	*s = NULL;
	return (-1);
}

int		next_line(char **buf, char **line, int len, char **buffer)
{
	char	*bufic;

	bufic = NULL;
	if (len < 0)
	{
		if (!(*line = ft_substr(*buf, 0, ft_strlen(*buf))))
			return (my_free(buf) * my_free(buffer) * -1);
	}
	else
	{
		if (!(*line = ft_substr(*buf, 0, len)))
			return (my_free(buf) * my_free(buffer) * -1);
		if (!(bufic = ft_substr(*buf, len + 1, \
						ft_strchr(*buf, '\0') - len - 1)))
			return (my_free(buf) * my_free(buffer) * -1);
	}
	free(*buf);
	*buf = NULL;
	*buf = bufic;
	free(*buffer);
	*buffer = NULL;
	if (!*buf)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	size_t		byte;
	static char	*buf = NULL;
	char		*bufic;

	if (!buf)
		buf = ft_strdup("");
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)) || !line || !buf || \
					fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (my_free(&buf) * my_free(&buffer) * -1);
	if (ft_strchr(buf, '\n') != -1)
		return (next_line(&buf, line, ft_strchr(buf, '\n'), &buffer));
	while ((byte = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[byte] = '\0';
		if (!(bufic = ft_strjoin(buf, buffer)))
			return (my_free(&buf) * my_free(&buffer) * -1);
		free(buf);
		buf = NULL;
		buf = bufic;
		if (ft_strchr(buf, '\n') != -1)
			break ;
	}
	return (next_line(&buf, line, ft_strchr(buf, '\n'), &buffer));
}

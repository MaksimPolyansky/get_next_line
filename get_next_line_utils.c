/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:21:34 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/12 16:36:15 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		k;
	int		p;

	if (!s2)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) \
									+ ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	k = 0;
	while (s1[k] != '\0')
	{
		str[k] = s1[k];
		k++;
	}
	p = 0;
	while (s2[p] != '\0')
	{
		str[k + p] = s2[p];
		p++;
	}
	str[k + p] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		n;
	char	*dst;

	if (!(dst = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		dst[n] = s[n];
		n++;
	}
	dst[n] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

ssize_t	ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)s;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

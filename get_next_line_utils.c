/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:00 by wlow              #+#    #+#             */
/*   Updated: 2021/08/11 15:44:08 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	index;

	if (s)
	{
		index = 0;
		while (s[index] != '\0')
			write(fd, &s[index++], 1);
	}
}

void	ft_bzero(void *string, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)string;
	i = 0;
	while (i < n)
		str[i++] = 0;
}

char	*ft_strdup(const char *string)
{
	char	*s_dup;
	int		i;

	i = 0;
	while (string[i])
		i++;
	s_dup = (char *) malloc (sizeof(*s_dup) * (i + 1));
	if (!s_dup)
		return (NULL);
	i = 0;
	while (string[i])
	{
		s_dup[i] = string[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;
	int				i;

	if (!s1 || !s2)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (s2[i++])
		len++;
	str = (char *) malloc (sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	return (str);
}

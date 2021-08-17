/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/18 01:26:34 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_newline(char *str, size_t *index, size_t str_len);

char	*get_next_line(int fd)
{
	static t_struct	tab;
	char			*ret_string;
	char			*temp1;
	char			*temp2;
	size_t			len;

	if (read(fd, NULL, 0) < 0)
		return (NULL);
	if (tab.n_read == 0)
	{
		tab.n_read = read(fd, tab.read_string, BUFFER_SIZE);
		tab.read_i = -1;
	}
	ret_string = NULL;
	tab.new_line = 0;
	while ((tab.n_read - tab.read_i - 1) > 0 && tab.new_line == 0)
	{
		tab.start = ++tab.read_i;
		tab.new_line = get_newline(tab.read_string, &tab.read_i, tab.n_read);
		len = tab.read_i - tab.start + 1;
		temp1 = (char *) malloc (sizeof(*temp1) * (len + 1));
		ft_memmove(temp1, &tab.read_string[tab.start], len);
		temp1[len] = '\0';
		if (!ret_string)
			ret_string = ft_strdup(temp1);
		else
		{
			temp2 = ft_strdup(ret_string);
			free(ret_string);
			ret_string = ft_strjoin(temp2, temp1);
			free(temp2);
		}
		free(temp1);
		if (tab.read_i == (size_t)(tab.n_read - 1))
		{
			tab.n_read = read(fd, tab.read_string, BUFFER_SIZE);
			tab.read_i = -1;
		}
	}
	return (ret_string);
}

int	get_newline(char *str, size_t *index, size_t str_len)
{
	while (*index < str_len)
	{
		if (str[*index] == '\n')
			return (1);
		*index += 1;
	}
	*index -= 1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/16 21:16:24 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_newline(char *str, size_t *index, size_t str_len);

char	*get_next_line(int fd)
{
	static t_struct	tab;
	char			*ret_string;
	size_t			len;

	if (read(fd, NULL, 0) < 0)
		return (NULL);
	if (tab.end_of_line == 0)
	{
		if (tab.end_of_file < 0)
			return (NULL);
		tab.n_read = read(fd, tab.read_string, BUFFER_SIZE);
		if (tab.n_read == 0)
			return (NULL);
		if (tab.n_read < BUFFER_SIZE)
			tab.end_of_file = -1;
		tab.read_i = -1;
	}
	tab.start = ++tab.read_i;
	tab.end_of_line = get_newline(tab.read_string, &tab.read_i, tab.n_read);
	len = tab.read_i - tab.start + 1;
	ret_string = (char *) malloc (sizeof(*ret_string) * (len + 1));
	ft_memmove(ret_string, &tab.read_string[tab.start], len);
	ret_string[len] = '\0';
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

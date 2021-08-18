/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/18 15:27:13 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_newline(char *str, size_t *index, size_t str_len);
void	save_line(char *ret_str, char *read_str);

char	*get_next_line(int fd)
{
	static t_struct	tab;
	char			*ret_string;
	char			*temp;
	char			*temp_another;
	size_t			len;

	if (read(fd, NULL, 0) < 0)
		return (NULL);
	if ((size_t)(tab.n_read) == tab.read_i)
	{
		tab.n_read = read(fd, tab.read_string, BUFFER_SIZE);
		tab.read_i = 0;
	}
	ret_string = NULL;
	tab.new_line = 0;
	while ((tab.n_read - tab.read_i) > 0 && tab.new_line == 0)
	{
		tab.start = tab.read_i;
		tab.new_line = get_newline(tab.read_string, &tab.read_i, tab.n_read);
		len = (tab.read_i - 1) - tab.start + 1;
		temp = (char *) malloc (sizeof(*temp) * (len + 1));
		ft_memmove(temp, &tab.read_string[tab.start], len);
		temp[len] = '\0';
		if (!ret_string)
			ret_string = ft_strdup(temp);
		else
		{
			temp_another = ft_strdup(ret_string);
			free(ret_string);
			ret_string = ft_strjoin(temp_another, temp);
			free(temp_another);
		}
		free(temp);
		if (tab.read_i == (size_t)(tab.n_read) && tab.new_line == 0)
		{
			tab.n_read = read(fd, tab.read_string, BUFFER_SIZE);
			tab.read_i = 0;
		}
	}
	return (ret_string);
}

int	get_newline(char *str, size_t *index, size_t str_len)
{
	while (*index < str_len)
	{
		if (str[*index] == '\n')
		{
			*index += 1;
			return (1);
		}
		*index += 1;
	}
	return (0);
}

void	save_line(char *ret_str, char *read_str)
{
	char	*temp;

	if (!ret_str)
		ret_str = ft_strdup(read_str);
	else
	{
		temp = ft_strdup(ret_str);
		free(ret_str);
		ret_str = ft_strjoin(temp, read_str);
		free(temp);
	}
	free(read_str);
}

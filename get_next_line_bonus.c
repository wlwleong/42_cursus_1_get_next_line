/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/18 23:12:03 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_newline(char *str, size_t *index, size_t str_len);
void	save(char **ret_str, size_t i_start, size_t i_end, void *ptr);

char	*get_next_line(int fd)
{
	static t_struct	t;
	char			*ret_str;

	if (read(fd, NULL, 0) < 0)
		return (NULL);
	if ((size_t)(t.n_read[fd]) == t.read_i[fd])
	{
		t.n_read[fd] = read(fd, t.read_str[fd], BUFFER_SIZE);
		t.read_i[fd] = 0;
	}
	ret_str = NULL;
	t.new_line = 0;
	while ((t.n_read[fd] - t.read_i[fd]) > 0 && t.new_line == 0)
	{
		t.start = t.read_i[fd];
		t.new_line = get_newline(t.read_str[fd], &t.read_i[fd], t.n_read[fd]);
		save(&ret_str, t.start, t.read_i[fd] - 1, &t.read_str[fd][t.start]);
		if (t.read_i[fd] == (size_t)(t.n_read[fd]) && t.new_line == 0)
		{
			t.n_read[fd] = read(fd, t.read_str[fd], BUFFER_SIZE);
			t.read_i[fd] = 0;
		}
	}
	return (ret_str);
}

int	get_newline(char *str, size_t *index, size_t str_len)
{
	while (*index < str_len)
	{
		if (str[(*index)++] == '\n')
			return (1);
	}
	return (0);
}

void	save(char **ret_str, size_t i_start, size_t i_end, void *ptr)
{
	char	*read_str;
	char	*temp;
	size_t	len;

	len = (i_end - i_start) + 1;
	read_str = (char *) malloc (sizeof(*read_str) * (len + 1));
	ft_memmove(read_str, ptr, len);
	read_str[len] = '\0';
	if (!*ret_str)
		*ret_str = ft_strdup(read_str);
	else
	{
		temp = ft_strdup(*ret_str);
		free(*ret_str);
		*ret_str = ft_strjoin(temp, read_str);
		free(temp);
	}
	free(read_str);
}

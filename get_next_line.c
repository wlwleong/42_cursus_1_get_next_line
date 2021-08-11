/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/11 20:59:12 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*get_next_line(int fd)
{
	char		*ret_string;
	static char	buffer_to_read[BUFFER_SIZE + 1];
	ssize_t		read_size;

	if (fd <= 0 || fd > 999 || BUFFER_SIZE < 0)
		return (NULL);
	ret_string = NULL;
	read_size = read(fd, buffer_to_read, BUFFER_SIZE);
	while (read_size > 0)
	{
		if (!ret_string)
			ret_string = ft_strdup(buffer_to_read);
		else
			ret_string = ft_strjoin(ret_string, buffer_to_read);
		read_size = read(fd, buffer_to_read, BUFFER_SIZE);
	}
	return (ret_string);
}

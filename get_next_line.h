/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:08 by wlow              #+#    #+#             */
/*   Updated: 2021/08/16 22:43:01 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
/*# include <sys/types.h>
# include <sys/stat.h>*/

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t count);

typedef struct s_struct
{
	char	read_string[BUFFER_SIZE];
	ssize_t	n_read;
	size_t	read_i;
	size_t	start;
	int		end_of_line;
}			t_struct;

#endif

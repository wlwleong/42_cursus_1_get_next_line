/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:08 by wlow              #+#    #+#             */
/*   Updated: 2021/08/28 14:45:39 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t count);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char const *s1, char const *s2);

typedef struct s_struct
{
	char	read_string[BUFFER_SIZE];
	ssize_t	n_read;
	size_t	read_i;
	size_t	start;
	int		new_line;
}			t_struct;

#endif

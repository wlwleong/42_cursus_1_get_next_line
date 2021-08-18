/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:08 by wlow              #+#    #+#             */
/*   Updated: 2021/08/18 23:05:20 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
/*# include <sys/types.h>
# include <sys/stat.h>*/

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t count);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char const *s1, char const *s2);

typedef struct s_struct
{
	char	read_str[FOPEN_MAX][BUFFER_SIZE];
	ssize_t	n_read[FOPEN_MAX];
	size_t	read_i[FOPEN_MAX];
	size_t	start;
	int		new_line;
}			t_struct;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:08 by wlow              #+#    #+#             */
/*   Updated: 2021/08/11 20:57:49 by wlow             ###   ########.fr       */
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
char	*ft_strdup(const char *string);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *string, size_t n);

#endif

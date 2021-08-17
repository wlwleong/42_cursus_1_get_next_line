/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/18 07:48:32 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);
char 	c;

int	main(int argc, char **argv)
{
	char	*file_name;
	int		fd;
	char	*file_content;

	file_name = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("ERROR: Invalid input argument(s)\n", 1);
		return (1);
	}
	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR: Unable to open file(s).\n", 1);
		return (1);
	}
	file_content = get_next_line(fd);
	printf("%s", file_content);
	c = 0;
	printf("%ld\n", read(fd, &c, 1));
	file_content = get_next_line(fd);
	printf("%s", file_content);
	printf("\n");
	free(file_content);
	fd = close(fd);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR: Unable to close file(s).\n", 1);
		return (1);
	}
	return (0);
}

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

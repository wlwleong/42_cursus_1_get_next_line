/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/18 23:06:19 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);

int	main(void)
{
	int	fd[4];

	fd[0] = open("41_with_nl", O_RDWR);
	fd[1] = open("42_with_nl", O_RDWR);
	fd[2] = open("43_with_nl", O_RDWR);
	fd[3] = open("nl", O_RDWR);
	printf("\n** 1 **\n");
	printf("Expected:\tNULL\n");
	printf("Actual:\t\t%s", get_next_line(1000));
	printf("\n** 2 **\n");
	printf("Expected:\t0123456789012345678901234567890123456789\n");
	printf("Actual:\t\t%s", get_next_line(fd[0]));
	printf("\n** 3 **\n");
	printf("Expected:\tNULL\n");
	printf("Actual:\t\t%s", get_next_line(1001));
	printf("\n** 4 **\n");
	printf("Expected:\t01234567890123456789012345678901234567890\n");
	printf("Actual:\t\t%s", get_next_line(fd[1]));
	printf("\n** 5 **\n");
	printf("Expected:\tNULL\n");
	printf("Actual:\t\t%s", get_next_line(1002));
	printf("\n** 6 **\n");
	printf("Expected:\t012345678901234567890123456789012345678901\n");
	printf("Actual:\t\t%s", get_next_line(fd[2]));
	printf("\n** 7 **\n");
	printf("Expected:\tNULL\n");
	printf("Actual:\t\t%s", get_next_line(1003));
	printf("\n** 8 **\n");
	printf("Expected:\t0\n");
	printf("Actual:\t\t%s\n", get_next_line(fd[0]));
	printf("\n** 9 **\n");
	printf("Expected:\tNULL\n");
	printf("Actual:\t\t%s\n", get_next_line(1004));
	printf("\n** 10 **\n");
	printf("Expected:\t1\n");
	printf("Actual:\t\t%s", get_next_line(fd[1]));
	printf("\n** 11 **\n");
	printf("Expected:\tNULL\n");
	printf("Actual:\t\t%s", get_next_line(1005));
	printf("\n** 12 **\n");
	printf("Expected:\t2\n");
	printf("Actual:\t\t%s\n", get_next_line(fd[2]));
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

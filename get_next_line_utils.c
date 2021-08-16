/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:10:00 by wlow              #+#    #+#             */
/*   Updated: 2021/08/16 20:33:25 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (count <= 0 || !dest || !src)
		return (dest);
	if (src > dest)
	{
		i = 0;
		while (i < count)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (count-- > 0)
			((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
	}
	return (dest);
}

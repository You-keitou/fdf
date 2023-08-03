/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:22:55 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/17 14:50:55 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const unsigned char	*p;
	unsigned char		c;

	p = buf;
	c = ch;
	while (n-- > 0)
	{
		if (*(p++) == c)
			return ((void *)(p - 1));
	}
	return (NULL);
}

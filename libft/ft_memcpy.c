/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 06:49:58 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/17 15:43:46 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*p1;
	unsigned const char	*p2;

	p1 = buf1;
	p2 = buf2;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	while (n--)
		*p1++ = *p2++;
	return (buf1);
}

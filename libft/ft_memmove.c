/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:13:28 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/16 19:44:59 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p1;
	const char	*p2;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		p1 = (char *)dst + len;
		p2 = (char *)src + len;
		while (len--)
			*--p1 = *--p2;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

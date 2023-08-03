/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:33:05 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/09 17:27:44 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = buf1;
	p2 = buf2;
	while (count-- > 0)
	{
		if (*(p1) != *(p2))
			return (*(p1) - *(p2));
		p1++;
		p2++;
	}
	return (0);
}

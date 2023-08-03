/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:49:40 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/22 21:20:10 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len_of_dest;
	unsigned int	len_of_src;
	unsigned int	temp;

	len_of_src = ft_strlen(src);
	len_of_dest = ft_strlen(dst);
	if (dstsize <= len_of_dest)
		return (dstsize + len_of_src);
	i = 0;
	temp = len_of_dest;
	while (src[i] != '\0' && i < dstsize - len_of_dest - 1)
	{
		dst[temp] = src[i];
		temp++;
		i++;
	}
	dst[temp] = '\0';
	return (len_of_dest + len_of_src);
}

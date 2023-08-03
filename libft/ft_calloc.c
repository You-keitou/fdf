/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:38:06 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/22 00:42:27 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	size_sum;

	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	size_sum = n * size;
	ptr = malloc(size_sum);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size_sum);
	return (ptr);
}

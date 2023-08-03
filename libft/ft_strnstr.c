/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:41:13 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/17 15:51:46 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	len_of_liitle;

	len_of_liitle = ft_strlen(little);
	i = 0;
	if (len_of_liitle == 0)
		return ((char *)big);
	while (big[i] != '\0' && i + len_of_liitle <= len)
	{
		if (ft_strncmp(big + i, little, len_of_liitle) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

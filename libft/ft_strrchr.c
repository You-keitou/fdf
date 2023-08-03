/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:11:00 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/17 15:07:17 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;
	const char		*last_p;
	unsigned char	ch;

	len = ft_strlen(s);
	last_p = s + len;
	ch = c;
	while (last_p != s)
	{
		if (*last_p == ch)
			return ((char *)last_p);
		last_p--;
	}
	if (*s == ch)
		return ((char *)last_p);
	return (NULL);
}

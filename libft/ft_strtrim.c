/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:31:59 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/17 06:24:30 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prepare(char **front_adress, char *end_adress, char const *set)
{
	char	*null_place;

	while (ft_strchr(set, *end_adress) != NULL)
	{
		if (end_adress <= *front_adress)
			break ;
		end_adress--;
	}
	null_place = end_adress + 1;
	*null_place = '\0';
	if (null_place > *front_adress)
	{
		while (ft_strchr(set, **front_adress) != NULL)
		{
			if ((*front_adress) + 1 < null_place)
				(*front_adress)++;
			else if ((*front_adress) + 1 == null_place)
			{
				(*front_adress)++;
				break ;
			}
		}
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	char	*result;
	char	*need_be_free;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	len = ft_strlen(s1);
	cpy = ft_strdup(s1);
	need_be_free = cpy;
	if (cpy == NULL)
		return (NULL);
	prepare(&cpy, cpy + len - 1, set);
	result = (char *)ft_strdup(cpy);
	if (result == NULL)
		return (NULL);
	free(need_be_free);
	return (result);
}

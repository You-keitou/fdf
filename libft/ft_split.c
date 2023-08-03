/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:28:04 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/22 18:14:05 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	change(char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			s[i] = '\0';
		else if (i == 0 || s[i - 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

static char	**make(char *s, int count)
{
	int		i;
	char	**result;

	i = 0;
	result = (char **)malloc((count + 1) * sizeof(char *));
	while (i < count)
	{
		if (*s != '\0')
		{
			result[i] = ft_strdup(s);
			if (result[i] == NULL)
			{
				while (--i >= 0)
					free(result[i]);
				return (NULL);
			}
			s += ft_strlen(result[i]) + 1;
			i++;
		}
		else
			s++;
	}
	result[count] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	*cpy;
	int		count;
	char	**result;

	if (s == NULL)
		return (NULL);
	cpy = ft_strdup(s);
	if (cpy == NULL)
		return (NULL);
	count = change(cpy, c);
	result = make(cpy, count);
	free(cpy);
	return (result);
}

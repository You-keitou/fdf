/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:13:09 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/18 04:07:57 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	p_overflow(long a, long b, bool flag)
{
	if (flag)
	{
		if (a > LONG_MAX - b)
			return (true);
		return (false);
	}
	else
	{
		if (a == 0 || b == 0)
			return (false);
		if (a > LONG_MAX / b)
			return (true);
		return (false);
	}
}

static bool	m_overflow(long a, long b, bool flag)
{
	if (flag)
	{
		if (a < LONG_MIN + b)
			return (true);
		return (false);
	}
	else
	{
		if (a == 0 || b == 0)
			return (false);
		if (a < LONG_MIN / b)
			return (true);
		return (false);
	}
}

static void	p_change(const char *nptr, long *result)
{
	int	len;

	len = ft_strlen(nptr);
	while (len-- > 0)
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			if (p_overflow(*result, 10, false))
			{
				*result = LONG_MAX;
				break ;
			}
			else
				*result *= 10;
			if (p_overflow(*result, *nptr - '0', true))
			{
				*result = LONG_MAX;
				break ;
			}
			else
				*result += (*(nptr++) - '0');
		}
		else
			break ;
	}
}

static void	m_change(const char *nptr, long *result)
{
	int	len;

	len = ft_strlen(nptr);
	while (len-- > 0)
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			if (m_overflow(*result, 10, false))
			{
				*result = LONG_MIN;
				break ;
			}
			else
				*result *= 10;
			if (m_overflow(*result, *nptr - '0', true))
			{
				*result = LONG_MIN;
				break ;
			}
			else
				*result -= (*(nptr++) - '0');
		}
		else
			break ;
	}
}

int	ft_atoi(const char *nptr)
{
	long	result;
	bool	flag;

	if (*nptr == '\0')
		return (0);
	result = 0;
	while (ft_strchr("\t\v\f\r\n ", *(nptr)) != NULL)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		flag = true;
	}
	else if (*nptr == '+')
	{
		nptr++;
		flag = false;
	}
	else
		flag = false;
	if (flag)
		m_change(nptr, &result);
	else
		p_change(nptr, &result);
	return ((int)result);
}

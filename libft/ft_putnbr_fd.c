/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 04:27:40 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/18 04:31:49 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long i)
{
	unsigned char	count;

	if (i == 0)
		return (1);
	count = 0;
	if (i < 0)
		i = -i;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static void	make_str(long m, unsigned char digit, char *result)
{
	unsigned char	index;

	if (m >= 0)
		index = digit - 1;
	else
	{
		m = m * (-1);
		index = digit;
		result[0] = '-';
	}
	while (m > 0)
	{
		result[index--] = '0' + m % 10;
		m /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char			result[12];
	unsigned char	digit;
	bool			flag;

	if (n >= 0)
		flag = false;
	else
		flag = true;
	digit = count_digit((long)n);
	result[digit + flag] = '\0';
	result[digit - 1 + flag] = '0';
	make_str((long)n, digit, result);
	ft_putstr_fd(result, fd);
}

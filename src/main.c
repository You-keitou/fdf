/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/04 08:27:55 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	char	*line;

	while(line = get_next_line(0))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	return 0;
}
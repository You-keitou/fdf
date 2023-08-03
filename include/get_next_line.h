/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:31:00 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/04 08:19:12 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_save
{
	char	*content;
	char	*cur;
	char	*cl_ptr;
	bool	flag;
}	t_save;

char	*get_next_line(int fd);
#endif
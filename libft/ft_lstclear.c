/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:07:15 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/21 19:50:35 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next_node;

	if (lst != NULL)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			next_node = tmp->next;
			if (del != NULL)
				del(tmp->content);
			free(tmp);
			tmp = next_node;
		}
		*lst = NULL;
	}
}

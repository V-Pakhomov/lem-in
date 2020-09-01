/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:17:03 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 21:24:55 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstrev(t_list **list)
{
	t_list *prev;
	t_list *next;

	prev = NULL;
	while (*list)
	{
		next = (*list)->next;
		(*list)->next = prev;
		prev = *list;
		*list = next;
	}
	*list = prev;
}

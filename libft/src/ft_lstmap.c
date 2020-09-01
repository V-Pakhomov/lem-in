/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:04:39 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 19:01:28 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst)
		return (NULL);
	new = f(lst);
	tmp = new;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (new);
}

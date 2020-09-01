/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:55:17 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 18:48:00 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		content_size = 0;
	}
	else if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	else if (!(new->content = ft_memcpy(new->content, content, content_size)))
	{
		free(new->content);
		free(new);
		return (NULL);
	}
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}

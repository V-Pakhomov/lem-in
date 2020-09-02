/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:21:11 by rciera            #+#    #+#             */
/*   Updated: 2020/09/02 18:28:38 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_queue.h"

static t_queue	*new_elem_queue(long long n)
{
	t_queue *new;

	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	new->num = n;
	new->next = NULL;
	return (new);
}

void			push_queue(t_queue **q, long long n)
{
	t_queue *tmp;
	t_queue *new;

	if (!(*q))
	{
		*q = new_elem_queue(n);
		return ;
	}
	tmp = *q;
	new = new_elem_queue(n);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

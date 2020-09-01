/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:47:41 by rciera            #+#    #+#             */
/*   Updated: 2020/08/29 13:58:57 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_queue.h"

static t_queue *new_elem_queue(long long n)
{
	t_queue *new;

	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	new->num = n;
	new->next = new;
	new->prev = new;
	return (new);
}

void push_queue(t_queue **q, long long n)
{
	t_queue *tmp;
	t_queue *new;

	tmp = *q;
	if (!tmp)
	{
		tmp = new_elem_queue(n);
		return ;
	}
	new = new_elem_queue(n);
	new->prev = tmp->prev;
	new->next = tmp;
	tmp->prev->next = new;
	tmp->prev = new;
}

void pop_queue(t_queue **q)
{
	t_queue *tmp;

	if ((*q)->next == *q)
	{
		free(*q);
		*q = NULL;
		return ;
	}
	tmp = *q;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	tmp = tmp->next;
	free(*q);
	*q = tmp;
}

long long front_queue(t_queue **q)
{
	return ((*q)->num);
}

long long back_queue(t_queue **q)
{
	return ((*q)->prev->num);
}

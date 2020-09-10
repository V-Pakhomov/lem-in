/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_neighbors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:20:51 by rciera            #+#    #+#             */
/*   Updated: 2020/09/10 15:46:53 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_neighbor	*new_neighbor(int n)
{
	t_neighbor *new;

	if (!(new = (t_neighbor*)malloc(sizeof(t_neighbor))))
		error_exit();
	new->room = n;
	new->next = NULL;
	return (new);
}

void				add_neighbor(t_neighbor **neighbor, int n)
{
	t_neighbor *new;

	new = new_neighbor(n);
	if (*neighbor == NULL)
	{
		*neighbor = new;
		return ;
	}
	new->next = *neighbor;
	*neighbor = new;
}

void				delete_neighbor(t_neighbor **neighbor, int n)
{
	t_neighbor *tmp;
	t_neighbor *next;

	if (*neighbor == NULL)
		return ;
	tmp = *neighbor;
	next = tmp->next;
	if ((*neighbor)->room == n)
	{
		free(*neighbor);
		*neighbor = next;
		return ;
	}
	while (next)
	{
		if (next->room == n)
		{
			tmp->next = next->next;
			free(next);
			return ;
		}
		tmp = next;
		next = next->next;
	}
}

int					is_neighbor(t_lemin *lemin, int n, int m)
{
	t_neighbor *tmp;

	tmp = lemin->adj_list[n];
	while (tmp)
	{
		if (tmp->room == m)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
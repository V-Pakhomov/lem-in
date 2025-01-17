/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:21:46 by rciera            #+#    #+#             */
/*   Updated: 2020/09/16 16:42:21 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	handle_vertex(t_lemin *lemin, t_queue **queue, long long vert)
{
	t_neighbor *nghbr;

	nghbr = lemin->adj_list[vert];
	while (nghbr)
	{
		if (!lemin->used[nghbr->room])
		{
			push_queue(queue, nghbr->room);
			lemin->parent[nghbr->room] = vert;
			lemin->path_len[nghbr->room] = lemin->path_len[vert] + 1;
			lemin->used[nghbr->room] = 1;
		}
		nghbr = nghbr->next;
	}
}

void		bfs(t_lemin *lemin)
{
	t_queue		*queue;
	long long	vert;

	queue = NULL;
	push_queue(&queue, lemin->start);
	lemin->path_len[lemin->start] = 0;
	lemin->used[lemin->start] = 1;
	while (!empty_queue(queue))
	{
		vert = front_queue(&queue);
		pop_queue(&queue);
		if (vert == lemin->end)
			break ;
		handle_vertex(lemin, &queue, vert);
	}
	while (!empty_queue(queue))
		pop_queue(&queue);
}

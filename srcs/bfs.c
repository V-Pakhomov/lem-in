/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:21:46 by rciera            #+#    #+#             */
/*   Updated: 2020/09/03 14:34:09 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs(t_lemin *lemin)
{
	t_queue		*queue;
	long long	vert;
	int			i;

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
		i = 0;
		while (i < lemin->vertices)
		{
			if (lemin->adj_matrix[vert][i] && !lemin->used[i])
			{
				push_queue(&queue, i);
				lemin->parent[i] = vert;
				lemin->path_len[i] = lemin->path_len[vert] + 1;
				lemin->used[i] = 1;
			}
			i++;
		}
	}
}

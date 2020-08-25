/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:21:46 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 18:44:33 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void bfs(t_lemin *lemin, long long start_vert, long long end_vert)
{
	t_queue		*queue;
	long long	vert;
	int i;

	queue = NULL;
	push_queue(&queue, start_vert);
	lemin->parent[start_vert] = -1;
	while (!empty_queue(queue))
	{
		vert = front_queue(&queue);
		pop_queue(&queue);
		lemin->used[vert] = 1;
		if (vert == end_vert)
			break ;
		i = 0;
		while (i < lemin->vertices)
		{
			if (lemin->adj_matrix[vert][i] && !lemin->used[i])
			{
				push_queue(&queue, i);
				lemin->parent[i] = vert;
			}
			i++;
		}
	}
	if (!lemin->used[end_vert])
	{
		ft_printf("path wasn't found\n");
		return ;
	}
	i = end_vert;
	while (lemin->parent[i] != -1)
	{
		ft_printf("%d -> ", i);
		i = lemin->parent[i];
	}
}
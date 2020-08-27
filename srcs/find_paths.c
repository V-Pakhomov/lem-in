/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:15:14 by rciera            #+#    #+#             */
/*   Updated: 2020/08/27 23:15:30 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void malloc_all(t_lemin *lemin)
{
	lemin->path = NULL;
	if (!(lemin->used = (int*)malloc(sizeof(int) * lemin->ants)) ||
		!(lemin->parent = (int*)malloc(sizeof(int) * lemin->ants)) ||
		!(lemin->path_len = (int*)malloc(sizeof(int) * lemin->ants)))
		error_exit();
}

static void reset_arrays_for_bfs(t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < lemin->ants)
	{
		lemin->used[i] = 0;
		lemin->path_len[i] = -1;
		i++;
	}
}

static void delete_vericies(t_lemin *lemin)
{
	int i;
	int j;

	i = lemin->parent[lemin->end];
	while (i != lemin->start)
	{
		j = 0;
		while (j < lemin->ants)
		{
			lemin->adj_matrix[i][j] = 0;
			lemin->adj_matrix[j++][i] = 0;
		}
		i = lemin->parent[i];
	}
}

int find_paths(t_lemin *lemin)
{
	reset_arrays_for_bfs(lemin);
	bfs(lemin);
	if (!lemin->used[lemin->end] ||
		lemin->max_path_len - lemin->path_len[lemin->end] < 2)
		return ;
	
}
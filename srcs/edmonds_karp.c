/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:15:14 by rciera            #+#    #+#             */
/*   Updated: 2020/09/21 20:51:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	malloc_all(t_lemin *lemin, int d_flag)
{
	lemin->path = NULL;
	if (!(lemin->used = (int*)malloc(sizeof(int) * lemin->vertices)) ||
		!(lemin->parent = (int*)malloc(sizeof(int) * lemin->vertices)) ||
		!(lemin->path_len = (int*)malloc(sizeof(int) * lemin->vertices)))
		error_exit(d_flag, "Failed to allocate memory for lemin structure");
	lemin->max_path_len = lemin->vertices + lemin->ants;
}

static void	reset_arrays_for_bfs(t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < lemin->vertices)
	{
		lemin->used[i] = 0;
		lemin->path_len[i] = -1;
		lemin->parent[i] = -1;
		i++;
	}
}

static void	delete_vericies(t_lemin *lemin)
{
	t_neighbor	*nghbr;
	int			i;
	int			j;

	i = lemin->parent[lemin->end];
	while (i != lemin->start)
	{
		nghbr = lemin->adj_list[i];
		while (nghbr)
		{
			j = nghbr->room;
			delete_neighbor(&(lemin->adj_list[j]), i);
			nghbr = nghbr->next;
		}
		i = lemin->parent[i];
	}
}

static int	find_path(t_lemin *lemin, int d_flag)
{
	bfs(lemin);
	if (!lemin->used[lemin->end] ||
		lemin->max_path_len - lemin->path_len[lemin->end] < 2)
		return (0);
	refresh_paths(lemin, d_flag);
	return (1);
}

void		edmonds_karp(t_lemin *lemin, int d_flag)
{
	if (is_neighbor(lemin, lemin->start, lemin->end))
		start_and_finish_are_connected(lemin);
	malloc_all(lemin, d_flag);
	reset_arrays_for_bfs(lemin);
	lemin->num_of_paths = 0;
	while (find_path(lemin, d_flag))
	{
		delete_vericies(lemin);
		reset_arrays_for_bfs(lemin);
	}
	if (!lemin->path)
		error_exit(d_flag, "No possible paths found");
	print_output(lemin);
}

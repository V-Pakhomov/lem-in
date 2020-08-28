/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:42:00 by rciera            #+#    #+#             */
/*   Updated: 2020/08/28 13:59:39 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	print_rooms(t_lemin *lemin)
{
	printf("ROOMS:\n");
	for (int i = 0; i < lemin->vertices; i++)
		printf("[%d] %s\n", i, lemin->rooms[i]);
}

void	print_adj_matrix(t_lemin *lemin)
{
	printf("%4c", '|');
	for (int i = 0; i < lemin->ants; i++)
		printf("%3d|", i);
	for (int i = 0; i < lemin->ants; i++)
	{
		printf("%*c\n", (lemin->ants + 1) * 4, '-');
		printf("%3d|", i);
		for (int j = 0; j < lemin->ants; j++)
			printf("%3d|", lemin->adj_matrix[i][j]);
	}
}

void	print_paths(t_lemin *lemin)
{
	t_path *tmp;

	tmp = lemin->path;
	while (tmp)
	{
		printf("%20c\n", '-');
		printf("first ant is number %d\nnumber of ants is %d\n", tmp->first_ant, tmp->ants);
		for (int i = 0; i < tmp->len; i++)
		{
			if (i)
				printf(" -> ");
			printf("%s", lemin->rooms[tmp->path[i]]);
		}
		printf("\n%20c\n", '-');
		tmp = tmp->next;
	}
}

void	print_lemin(t_lemin *lemin)
{
	printf("\nstart = [%d] %s\nend = [%d] %s\n\n", lemin->start, lemin->end);
	print_rooms(lemin);
	print_adj_matrix(lemin);
	print_paths(lemin);
}
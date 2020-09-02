/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:42:00 by rciera            #+#    #+#             */
/*   Updated: 2020/09/02 17:37:08 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	debug_print_rooms(t_lemin *lemin)
{
	printf("ROOMS:\n");
	for (int i = 0; i < lemin->vertices; i++)
	{
		printf("[%d] %s", i, lemin->rooms[i]);
		if (i == lemin->start)
			printf(" %s##START%s\n", BLUE, RESET);
		else if (i == lemin->end)
			printf(" %s##END%s\n", RED, RESET);
		else
			printf("\n");
	}
}

void	print_adj_matrix(t_lemin *lemin)
{
	printf("%4c", '|');
	for (int i = 0; i < lemin->vertices; i++)
	{
		if (i == lemin->start)
			printf("%s", BLUE);
		if (i == lemin->end)
			printf("%s", RED);
		printf("%3d%s|", i, RESET);
	}
	for (int i = 0; i < lemin->vertices; i++)
	{
		printf("\n");
		for (int j = 0; j < (lemin->vertices + 1) * 4; j++)
			printf("-");
		if (i == lemin->start)
			printf("%s", BLUE);
		if (i == lemin->end)
			printf("%s", RED);
		printf("\n%3d%s|", i, RESET);
		for (int j = 0; j < lemin->vertices; j++)
		{
			if (lemin->adj_matrix[i][j])
				printf("%s", GREEN);
			printf(" %d %s|", lemin->adj_matrix[i][j], RESET);
		}
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
	debug_print_rooms(lemin);
	print_adj_matrix(lemin);
	//print_paths(lemin);
}
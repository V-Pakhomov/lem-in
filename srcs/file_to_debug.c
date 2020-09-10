/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:42:00 by rciera            #+#    #+#             */
/*   Updated: 2020/09/10 16:30:39 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	print_rooms(t_lemin *lemin)
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

void	print_adj_list(t_lemin *lemin)
{
	t_neighbor *nghbr;

	for (int i = 0; i < lemin->vertices; i++)
	{
		nghbr = lemin->adj_list[i];
		if (i == lemin->start)
			printf("%s", BLUE);
		if (i == lemin->end)
			printf("%s", RED);
		printf("%d%s : ", i, RESET);
		while (nghbr)
		{
			if (nghbr->room == lemin->start)
				printf("%s", BLUE);
			if (nghbr->room == lemin->end)
				printf("%s", RED);
			printf("| %d |%s", nghbr->room, RESET);
			nghbr = nghbr->next;
		}
		printf("\n");
	}
	printf("\n");
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

void	print_bfs_info(t_lemin *lemin)
{
	//debug_print_rooms(lemin);
	ft_printf("used:\n");
	for (int i = 0; i < lemin->vertices; i++)
		ft_printf("[%d] %d| ", i, lemin->used[i]);
	ft_printf("\nparents:\n");
	for (int i = 0; i < lemin->vertices; i++)
		ft_printf("[%d] %d| ", i, lemin->parent[i]);
	ft_printf("\nlen of path:\n");
	for (int i = 0; i < lemin->vertices; i++)
		ft_printf("[%d] %d| ", i, lemin->path_len[i]);
	ft_printf("\n");
}

void	print_lemin(t_lemin *lemin)
{
	print_rooms(lemin);
	print_adj_list(lemin);
	//print_paths(lemin);
}
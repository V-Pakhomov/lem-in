/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:58:39 by rciera            #+#    #+#             */
/*   Updated: 2020/09/21 21:03:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		intialize_adjacency_list(t_lemin *lemin, int d_flag)
{
	t_link	*links;
	int		i;
	int		j;

	if (!(lemin->adj_list = (t_neighbor**)malloc(sizeof(t_neighbor*) *
												lemin->vertices)))
		error_exit(d_flag, "Failed to allocate memory for adjacency list");
	i = 0;
	j = 0;
	while (i < lemin->vertices)
		lemin->adj_list[i++] = NULL;
	links = lemin->links;
	while (links)
	{
		i = room_num(lemin, links->first);
		j = room_num(lemin, links->last);
		if (i == -1 || j == -1)
			error_exit(d_flag, "Adjacency list: filling up error");
		add_neighbor(&(lemin->adj_list[i]), j, d_flag);
		add_neighbor(&(lemin->adj_list[j]), i, d_flag);
		links = links->next;
	}
}

static void	init_start_and_end(t_lemin *lemin, char **start, char **end, int d_flag)
{
	if (*start == NULL || *end == NULL)
		error_exit(d_flag, "Failed to define start or end node");
	ft_qsort(lemin);
	lemin->start = room_num(lemin, *start);
	lemin->end = room_num(lemin, *end);
	if (lemin->start == -1 || lemin->end == -1)
		error_exit(d_flag, "Failed to define start or end node");
	free(*start);
	free(*end);
}

void		init_room_names_dict(t_lemin *lemin, int d_flag)
{
	t_room	*rooms;
	int		i;
	char	*start;
	char	*end;

	if (!(lemin->rooms = (char **)malloc(sizeof(char *) * lemin->vertices)))
		error_exit(d_flag, "Failed to alocate memory for rooms");
	rooms = lemin->rooms_raw;
	start = NULL;
	end = NULL;
	i = 0;
	while (rooms)
	{
		if ((rooms->is_cmd == 1 && start != NULL) ||
			(rooms->is_cmd == 2 && end != NULL))
			error_exit(d_flag, "More than one start or end node has been found");
		if (rooms->is_cmd == 1)
			start = ft_strdup(rooms->name);
		else if (rooms->is_cmd == 2)
			end = ft_strdup(rooms->name);
		lemin->rooms[i] = ft_strdup(rooms->name);
		i++;
		rooms = rooms->next;
	}
	init_start_and_end(lemin, &start, &end, d_flag);
}

t_lemin		*lemin_init(int d_flag)
{
	t_lemin *out;

	if (!(out = (t_lemin *)malloc(sizeof(t_lemin))))
		error_exit(d_flag, "Failed to allocate memory for lemin global structure");
	out->links = 0;
	out->max_path_len = 0;
	out->num_of_paths = 0;
	out->parent = 0;
	out->path = 0;
	out->path_len = 0;
	out->rooms = 0;
	out->rooms = 0;
	out->start = 0;
	out->used = 0;
	out->vertices = 0;
	out->adj_list = 0;
	out->ants = 0;
	out->end = 0;
	out->input_raw = 0;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:58:39 by rciera            #+#    #+#             */
/*   Updated: 2020/09/20 22:41:42 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		intialize_adjacency_list(t_lemin *lemin)
{
	t_link	*links;
	int		i;
	int		j;

	if (!(lemin->adj_list = (t_neighbor**)malloc(sizeof(t_neighbor*) *
												lemin->vertices)))
		error_exit();
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
			error_exit();
		add_neighbor(&(lemin->adj_list[i]), j);
		add_neighbor(&(lemin->adj_list[j]), i);
		links = links->next;
	}
}

static void	init_start_and_end(t_lemin *lemin, char **start, char **end)
{
	if (*start == NULL || *end == NULL)
		error_exit();
	ft_qsort(lemin);
	lemin->start = room_num(lemin, *start);
	lemin->end = room_num(lemin, *end);
	if (lemin->start == -1 || lemin->end == -1)
		error_exit();
	free(*start);
	free(*end);
}

void		init_room_names_dict(t_lemin *lemin)
{
	t_room	*rooms;
	int		i;
	char	*start;
	char	*end;

	if (!(lemin->rooms = (char **)malloc(sizeof(char *) * lemin->vertices)))
		error_exit();
	rooms = lemin->rooms_raw;
	start = NULL;
	end = NULL;
	i = 0;
	while (rooms)
	{
		if ((rooms->is_cmd == 1 && start != NULL) ||
			(rooms->is_cmd == 2 && end != NULL))
			error_exit();
		if (rooms->is_cmd == 1)
			start = ft_strdup(rooms->name);
		else if (rooms->is_cmd == 2)
			end = ft_strdup(rooms->name);
		lemin->rooms[i] = ft_strdup(rooms->name);
		i++;
		rooms = rooms->next;
	}
	init_start_and_end(lemin, &start, &end);
}

t_lemin		*lemin_init(void)
{
	t_lemin *out;

	if (!(out = (t_lemin *)malloc(sizeof(t_lemin))))
		error_exit();
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

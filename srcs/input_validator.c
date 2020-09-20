/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:11:34 by rciera            #+#    #+#             */
/*   Updated: 2020/09/20 18:21:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	check_links(t_lemin *lemin)
{
	t_link *link;

	link = lemin->links;
	while (link)
	{
		if (room_num(lemin, link->first) == -1 ||
			room_num(lemin, link->last) == -1)
			error_exit();
		if (ft_strequ(link->first, link->last))
			error_exit();
		link = link->next;
	}
}

static void	check_repeating_rooms(t_lemin *lemin)
{
	int i;
	t_room *ptr;
	t_room *ptr2;

	i = 1;
	ptr = lemin->rooms_raw;
	while (i < lemin->vertices)
	{
		if (ft_strequ(lemin->rooms[i], lemin->rooms[i - 1]))
			error_exit();
		i++;
	}
	while(ptr != 0)
	{
		ptr2 = ptr->next;
		while(ptr2 != 0)
		{
			if (ptr->x == ptr2->x && ptr->y == ptr2->y)
				error_exit();
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

static int	handle_line(char *line, t_link **links, t_room **rooms, int *cmd)
{
	char **link;

	if (!line || line[0] == '\0' || line[0] == ' ' || line[0] == 'L')
		error_exit();
	if (is_comment(line))
		return (0);
	if (is_room(line))
	{
		add_room(rooms, line, *cmd);
		*cmd &= 4;
		return (1);
	}
	if (is_link(line))
	{
		link = ft_strsplit(line, '-');
		add_link(links, link[0], link[1]);
		ft_arrayfree(link);
	}
	else if (ft_strequ("##start", line))
		*cmd = (*cmd) |= 1;
	else if (ft_strequ("##end", line))
		*cmd = (*cmd) |= 2;
	else
		error_exit();
	return (0);
}

void input_free(t_input **in)
{
	t_input *tmp;

	while(*in != 0)
	{
		tmp = (*in)->next;
		free((*in)->line);
		free(*in);
		*in = tmp;
	}
	free(in);
}

t_input *get_all_input()
{
	char *line;
	t_input *input;

	line = 0;
	input = 0;
	while (get_next_line(0, &line))
	{
		add_input(&input, line);
		if (line)
			free(line);
	}
	return(input);
}

void handle_input(t_input *in, t_lemin *lemin)
{
	t_input *ptr;
	int cmd_flag;
	t_room	*rooms;
	t_link	*links;

	ptr = in;
	cmd_flag = 0;
	rooms = 0;
	links = 0;
	while(ptr->next != 0)
		ptr = ptr->next;
	while(ptr != 0)
	{
		if (ft_isinteger(ptr->line) && !(cmd_flag & (1 << 2)))
		{
			lemin->ants = ft_atoi(ptr->line);
			cmd_flag |= 4;
		}
		else
			lemin->vertices += handle_line(ptr->line, &links, &rooms, &cmd_flag);
		ptr = ptr->prev;
	}
	lemin->links = links;
	lemin->rooms_raw = rooms;
}

t_lemin *lemin_init()
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

void check_repeating_pipes(t_lemin *lemin)
{
	t_link *ptr1;
	t_link *ptr2;
	int i;

	ptr1 = lemin->links;
	i = 0;
	while(ptr1 != 0)
	{
		ptr2 = ptr1->next;
		while(ptr2 != 0)
		{
			i = 0;
			if (ft_strequ(ptr1->first, ptr2->first))
				i++;
			if (ft_strequ(ptr1->first, ptr2->last))
				i++;
			if (ft_strequ(ptr1->last, ptr2->last))
				i++;
			if (ft_strequ(ptr1->last, ptr2->first))
				i++;
			if (i >= 2)
				error_exit();
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

void		parse_input(t_lemin *lemin)
{
	lemin->input_raw = get_all_input();
	handle_input(lemin->input_raw, lemin);
}

int			main(int argc, char **argv)
{
	t_lemin *lemin;

	if (argc > 1 && argv)
		error_exit();
	lemin = lemin_init();
	lemin->input_raw = get_all_input();
	handle_input(lemin->input_raw, lemin);
	if (lemin->ants <= 0 || lemin->vertices == 0 || lemin->links == NULL)
		error_exit();
	init_room_names_dict(lemin);
	check_repeating_rooms(lemin);
	//check_repeating_pipes(lemin);
	check_links(lemin);
	intialize_adjacency_list(lemin);
	edmonds_karp(lemin);
}

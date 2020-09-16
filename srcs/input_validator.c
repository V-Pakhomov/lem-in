/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:11:34 by rciera            #+#    #+#             */
/*   Updated: 2020/09/16 19:19:29 by rciera           ###   ########.fr       */
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
		link = link->next;
	}
}

static void	check_repeating_rooms(t_lemin *lemin)
{
	int i;

	i = 1;
	while (i < lemin->vertices)
	{
		if (ft_strequ(lemin->rooms[i], lemin->rooms[i - 1]))
			error_exit();
		i++;
	}
}

static int	handle_line(char *line, t_link **links, t_room **rooms, int *cmd)
{
	char **link;

	if (is_comment(line))
		return (0);
	if (is_room(line)/* && check_dup_elem(line, *rooms)*/)
	{
		add_room(rooms, line, *cmd);
		*cmd = 0;
		return (1);
	}
	if (is_link(line))
	{
		link = ft_strsplit(line, '-');
		add_link(links, link[0], link[1]);
		ft_arrayfree(link);
	}
	else if (ft_strequ("##start", line))
		*cmd = 1;
	else if (ft_strequ("##end", line))
		*cmd = 2;
	else
		error_exit();
	return (0);
}

void		parse_input(t_lemin *lemin)
{
	char	*line;
	t_room	*rooms;
	t_link	*links;
	int		cmd_flag;

	rooms = 0;
	links = 0;
	lemin->vertices = 0;
	lemin->links = 0;
	cmd_flag = 0;
	if (get_next_line(0, &line) && ft_isinteger(line))
		lemin->ants = ft_atoi(line);
	else
		error_exit();
	free(line);
	while (get_next_line(0, &line))
	{
		lemin->vertices += handle_line(line, &links, &rooms, &cmd_flag);
		if (line)
			free(line);
	}
	lemin->links = links;
	lemin->rooms_raw = rooms;
}

int			main(int argc, char **argv)
{
	t_lemin lemin;

	if (argc > 1 && argv)
		error_exit();
	parse_input(&lemin);
	if (lemin.ants <= 0 || lemin.vertices == 0 || lemin.links == NULL)
		error_exit();
	init_room_names_dict(&lemin);
	check_repeating_rooms(&lemin);
	check_links(&lemin);
	intialize_adjacency_list(&lemin);
	edmonds_karp(&lemin);
}

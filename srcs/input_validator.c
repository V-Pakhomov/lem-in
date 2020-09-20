/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:11:34 by rciera            #+#    #+#             */
/*   Updated: 2020/09/20 23:32:49 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
		*cmd |= 1;
	else if (ft_strequ("##end", line))
		*cmd |= 2;
	else
		error_exit();
	return (0);
}

t_input		*get_all_input(void)
{
	char	*line;
	t_input	*input;

	line = 0;
	input = 0;
	while (get_next_line(0, &line))
	{
		add_input(&input, line);
		if (line)
			free(line);
	}
	return (input);
}

void		handle_input(t_input *in, t_lemin *lemin)
{
	t_input	*ptr;
	int		cmd_flag;
	t_room	*rooms;
	t_link	*links;

	ptr = in;
	cmd_flag = 0;
	rooms = 0;
	links = 0;
	while (ptr->next != 0)
		ptr = ptr->next;
	while (ptr != 0)
	{
		if (ft_isinteger(ptr->line) && !(cmd_flag & (1 << 2)))
		{
			lemin->ants = ft_atoi(ptr->line);
			cmd_flag |= 4;
		}
		else
			lemin->vertices +=
				handle_line(ptr->line, &links, &rooms, &cmd_flag);
		ptr = ptr->prev;
	}
	lemin->links = links;
	lemin->rooms_raw = rooms;
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
	check_links(lemin);
	intialize_adjacency_list(lemin);
	edmonds_karp(lemin);
}

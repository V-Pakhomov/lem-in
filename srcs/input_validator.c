/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:11:34 by rciera            #+#    #+#             */
/*   Updated: 2020/09/25 20:57:15 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	handle_line(char *line, t_lemin *l, int *cmd, int d_flag)
{
	char **link;

	if (!line || line[0] == '\0' || line[0] == ' ' || line[0] == 'L')
		error_exit(d_flag, "Wrong line format");
	if (is_comment(line))
		return (0);
	if (is_room(line))
	{
		add_room(&l->rooms_raw, line, *cmd);
		*cmd &= 4;
		return (1);
	}
	if (is_link(line))
	{
		link = ft_strsplit(line, '-');
		add_link(&l->links, link[0], link[1]);
		ft_arrayfree(link);
	}
	else if (ft_strequ("##start", line))
		*cmd |= 1;
	else if (ft_strequ("##end", line))
		*cmd |= 2;
	else
		error_exit(d_flag, "Undefined wrong line format");
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

void		handle_input(t_input *in, t_lemin *lemin, int d_flag)
{
	t_input	*ptr;
	int		cmd_flag;
	t_room	*rooms;

	ptr = in;
	cmd_flag = 0;
	rooms = 0;
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
				handle_line(ptr->line, lemin, &cmd_flag, d_flag);
		ptr = ptr->prev;
	}
}

int			main(int argc, char **argv)
{
	t_lemin	*lemin;
	int		d_flag;

	if (argc > 1 && ft_strequ(argv[1], "-d"))
		d_flag = 1;
	else
		d_flag = 0;
	lemin = lemin_init(d_flag);
	lemin->input_raw = get_all_input();
	handle_input(lemin->input_raw, lemin, d_flag);
	if (lemin->ants <= 0 || lemin->vertices == 0 || lemin->links == NULL)
		error_exit(d_flag, "Incomplete input error");
	init_room_names_dict(lemin, d_flag);
	check_repeating_rooms(lemin, d_flag);
	check_links(lemin, d_flag);
	intialize_adjacency_list(lemin, d_flag);
	edmonds_karp(lemin, d_flag);
}

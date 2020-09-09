#include "lemin.h"



int get_index(char *room, char **rooms)
{
	int i;
	i = 0;
	while(rooms[i] != 0)
	{
		if (!ft_strcmp(rooms[i], room))
			return(i);
		i++;
	}
	return (-1);
}


void fill_matrix(t_lemin *lemin, t_link *links)
{
	int i;
	int j;

	while(links)
	{
		i = room_num(lemin, links->first);
		j = room_num(lemin, links->last);
		if (i == -1 || j == - 1)
			ft_printf("ooops");
		lemin->adj_matrix[i][j] = 1;
		lemin->adj_matrix[j][i] = 1;
		links = links->next;
	}
}

int rooms_exists(t_room *rooms, t_link *links)
{
	t_room *ptr;
	int first_ok;
	int last_ok;

	first_ok = 0;
	last_ok = 0;

	ptr = rooms;
	while(ptr != 0)
	{
		if (ft_strequ(ptr->name, links->first))
			first_ok++;
		if (ft_strequ(ptr->name, links->last))
			last_ok++;
		ptr = ptr->next;
	}
	if (first_ok && last_ok)
		return (1);
	return(0);
}

int final_validation(t_room *rooms, t_link *links, t_lemin *lemin)
{
	int counter = 0;
	int counter_2 = 0;
	int start_existing_flag = 0;
	int end_existing_flag = 0;
	if (lemin->ants <= 0)
		error_exit();
	t_room *ptr = rooms;
	t_link *lnk = links;
	while(ptr != 0)
	{
		if (ptr->is_cmd == 1)
			start_existing_flag++;
		if (ptr->is_cmd == 2)
			end_existing_flag++;
		ptr = ptr->next;
		counter++;
	}
	while(lnk != 0)
	{
		if (!rooms_exists(rooms, lnk))
			return(0);
		lnk = lnk->next;
		counter_2++;
	}
	if (!counter || !counter_2 ||
			start_existing_flag != 1 || end_existing_flag != 1)
		return (0);
	return(1);
}

void	parse_input(t_lemin *lemin)
{
	char	*line = 0;
	int fd;
	t_room *rooms;
	t_link *links;
	char **room = 0;
	char **link = 0;
	int cmd_flag;

	room = 0;
	fd = 0;
	rooms = 0;
	links = 0;
	lemin->vertices = 0;
	cmd_flag = 0;
	if (get_next_line(fd, &line) && ft_isinteger(line))
		lemin->ants = ft_atoi(line);
	else
		error_exit();
	free(line);
	while (get_next_line(fd, &line))
	{
		if (is_comment(line))
		{
		}
		else if (is_link(line))
		{
			link = ft_strsplit(line, '-');
			add_link(&links, link[0], link[1]);
		}
		else if (is_room(line) && check_dup_elem(line, rooms))
		{
			add_room(&rooms, line, cmd_flag);
			lemin->vertices++;
			cmd_flag = 0;
		}
		else if (ft_strequ("##start", line))
			cmd_flag = 1;
		else if (ft_strequ("##end", line))
			cmd_flag = 2;
		else
			error_exit();
		if (line)
			free(line);
	}
	if (!final_validation(rooms, links, lemin))
		error_exit();
	lemin->adj_matrix = intialize_adjacency_matrix(lemin->vertices);
	init_room_names_dict(rooms, lemin);
	fill_matrix(lemin, links);
}

int main(void)
{

	t_lemin lemin;

	parse_input(&lemin);
	edmonds_karp(&lemin);
	//print_lemin(&lemin);
}

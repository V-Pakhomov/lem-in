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

void	parse_input(t_lemin *lemin)
{
	char	*line = 0;
	int fd;
	t_room *rooms;
	t_link *links;
	char **room = 0;
	char **link = 0;
	int **matrix;
	int cmd_flag;

	room = 0;
	fd = 0;
	matrix = 0;
	rooms = 0;
	links = 0;
	lemin->vertices = 0;
	cmd_flag = 0;
	//if (fd < 0)
		//error handler
	while (get_next_line(fd, &line))
	{	
		//ft_printf("inside");
		if (is_comment(line))
		{
			//ft_printf("comment detected\n");
		}
		else if (is_link(line))
		{
			link = ft_strsplit(line, '-');
			add_link(&links, link[0], link[1]);
			//ft_printf("link detected\n");
		}
		else if (is_room(line))
		{
			//ft_printf("room_detected\n");
			room = ft_strsplit(line, ' ');
			add_room(&rooms, room[0], cmd_flag);
			lemin->vertices++;
			cmd_flag = 0;
		}
		else if (ft_strequ("##start", line))
			cmd_flag = 1;
		else if (ft_strequ("##end", line))
			cmd_flag = 2;
		if (line)
			free(line);
	}

	//ft_printf("starting init matrix\n");
	lemin->adj_matrix = intialize_adjacency_matrix(lemin->vertices);
	//ft_printf("init finished\n");
	//print_matrix(lemin->adj_matrix, lemin->vertices);
	init_room_names_dict(rooms, lemin);

	fill_matrix(lemin, links);

	//return (lemin);
}

int main(void)
{

	t_lemin lemin;

	parse_input(&lemin);
	// lemin->start = get_index("start", lemin->rooms);
	// lemin->end = get_index("end", lemin->rooms);

	//print_lst_of_rooms(lemin.rooms);
	//print_matrix(lemin.adj_matrix, lemin.vertices);
	edmonds_karp(&lemin);
	//print_lemin(&lemin);
}

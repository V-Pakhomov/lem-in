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


void fill_matrix(int **matrix, t_link *links, char **rooms)
{
	t_link *pointer;
	int i;

	pointer = links;
	i = 0;

	while(pointer != 0)
	{
		int a = get_index(pointer->first, rooms);
		int b = get_index(pointer->last, rooms);
		if (a == -1 || b == - 1)
			ft_printf("ooops");
		matrix[a][b] = 1;
		matrix[b][a] = 1;
		pointer = pointer->next;
	}
}

t_lemin *parse_input(void)
{
	t_lemin *lemin = 0;
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
	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	lemin->vertices = 0;
	cmd_flag = 0;
	//if (fd < 0)
		//error handler
	while (get_next_line(fd, &line))
	{
		ft_printf("inside");
		if (is_comment(line))
		{
			ft_printf("comment detected\n");
		}
		else if (is_link(line))
		{
			link = ft_strsplit(line, '-');
			add_link(&links, link[0], link[1]);
			ft_printf("link detected\n");
		}
		else if (is_room(line))
		{
			ft_printf("room_detected\n");
			room = ft_strsplit(line, ' ');
			add_room(&rooms, room[0], cmd_flag);
			lemin->vertices = lemin->vertices + 1;
			cmd_flag = 0;
		}
		else if (ft_strcmp("##start", line))
			cmd_flag = 1;
		else if (ft_strcmp("##end", line))
			cmd_flag = 2;
		if (line)
			free(line);
	}

	ft_printf("starting init matrix\n");
	lemin->adj_matrix = intialize_adjacency_matrix(lemin->vertices);
	ft_printf("init finished\n");
	print_matrix(lemin->adj_matrix, lemin->vertices);
	lemin->rooms = init_room_names_dict(rooms, lemin);
	ft_qsort(lemin);

	fill_matrix(lemin->adj_matrix, links, lemin->rooms);

	return (lemin);
}

int main(void)
{

	t_lemin *lemin = 0;

	lemin = parse_input();
	// lemin->start = get_index("start", lemin->rooms);
	// lemin->end = get_index("end", lemin->rooms);

	print_lst_of_rooms(lemin->rooms);
	print_matrix(lemin->adj_matrix, lemin->vertices);

}

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

t_lemin *parse_input(char *filename)
{
	t_lemin *lemin = 0;
	char	*line = 0;
	int		matrix_size;
	int fd;
	t_room *rooms;
	t_link *links;
	char **room = 0;
	char **link = 0;
	int **matrix;

	matrix_size = 0;
	room = 0;
	fd = open(filename, O_RDONLY, 0);
	matrix = 0;
	rooms = 0;
	links = 0;
	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	//if (fd < 0)
		//error handler
	while (get_next_line(fd, &line))
	{
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
			add_room(&rooms, room[0]);
			matrix_size++;
		}
		else if (is_cmd(line))
		{
			ft_printf("cmd detected\n");
		}
		if (line)
			free(line);
	}

	ft_printf("starting init matrix\n");
	matrix_size++; //nodes need to be counted starting from 1
	lemin->adj_matrix = intialize_adjacency_matrix(matrix_size);
	ft_printf("init finished\n");

	lemin->rooms = init_room_names_dict(rooms, matrix_size);

	fill_matrix(lemin->adj_matrix, links, lemin->rooms);

	return (lemin);
}

int main(int argc, char **argv)
{
	if (argc > 100)
		return(0);

	t_lemin *lemin = 0;

	lemin = parse_input(argv[1]);
	lemin->start = get_index("start", lemin->rooms);
	lemin->end = get_index("end", lemin->rooms);

	print_lst_of_rooms(lemin->rooms);
	print_matrix(lemin->adj_matrix, 8);

}

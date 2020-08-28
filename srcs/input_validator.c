#include "/Users/admin/school_21/lemin/libft/libft.h"
#include "input.h"



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

int **parse_input(char *filename)
{
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
	matrix = intialize_adjacency_matrix(matrix_size);
	ft_printf("init finished\n");

	print_matrix(matrix, matrix_size);

	char **room_names = init_room_names_dict(rooms, matrix_size);

	print_lst_of_rooms(room_names);

	fill_matrix(matrix, links, room_names);

	print_matrix(matrix, matrix_size);

	return (matrix);
}

int main(int argc, char **argv)
{
	if (argc > 100)
		return(0);
	parse_input(argv[1]);
}

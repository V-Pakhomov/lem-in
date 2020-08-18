#include "/Users/admin/school_21/lemin/libft/libft.h"
#include "input.h"

int is_comment(char *s)
{
	int i;

	i = 0;
	if (s[i] == '#' && s[i + 1] != '#')
		return (1);
	return (0);
}

int is_cmd(char *s)
{
	int i;
	i = 0;

	char *cmd_start = "##start";
	char *cmd_end = "##end";
	if (ft_strcmp(cmd_start, s) || ft_strcmp(cmd_end, s))
		return (1);
	return(0);
}

int is_room(char *s)
{
	int i;
	char **s_for_inspect;

	i = 0;
	s_for_inspect = ft_strsplit(s, ' ');
	if (ft_arraylen(s_for_inspect) == 3 && ft_isinteger(s_for_inspect[1]) && ft_isinteger(s_for_inspect[2]))
		return (1);
	return (0);
}


int is_link(char *s)
{
	int i;
	char **s_for_inspect;

	i = 0;
	s_for_inspect = ft_strsplit(s, '-');
	if (ft_arraylen(s_for_inspect) == 2)
		return (1);
	return (0);
}

void input(char *filename)
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
			links = new_link(link[0], link[1]);
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
}

int main(int argc, char **argv)
{
	if (argc > 100)
		return(0);
	input(argv[1]);
}

#include "lemin.h"


int **intialize_adjacency_matrix(int size)
{
	int i;
	int j;
	int *line;
	int **matrix;

	i = 0;
	j = 0;
	line = 0;
	matrix = 0;
	if (!(matrix = (int **)malloc(sizeof(int *) * size)))
		return (0);
	while(i < size)
	{
		j = 0;
		if (!(matrix[i] = (int *)malloc(sizeof(int) * size)))
			return(0);
		while(j < size)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_link *new_link(char *first, char *last)
{
	t_link *new;

	if (!(new = (t_link *)malloc(sizeof(t_link))))
		return (0);
	new->first = ft_strdup(first);
	new->last = ft_strdup(last);
	new->next = 0;
	return(new);
}

t_room *new_room(char *name, int cmd_flag)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(name);
	new->next = 0;
	new->is_cmd = cmd_flag;
	return(new);
}

void add_room(t_room **all_lst, char *name, int cmd_flag)
{
	t_room *new;

	if (*all_lst != NULL)
	{
		new = new_room(name, cmd_flag);
		new->next = *all_lst;
		*all_lst = new;
	}
	else
		*all_lst = new_room(name, cmd_flag);
}

void add_link(t_link **all_lst, char *first, char *last)
{
	t_link *new;

	if (*all_lst != NULL)
	{
		new = new_link(first, last);
		new->next = *all_lst;
		*all_lst = new;
	}
	else
		*all_lst = new_link(first, last);
}

void	init_room_names_dict(t_room *rooms, t_lemin *lemin)
{
	int i;
	char *start;
	char *end;

	if (!(lemin->rooms = (char **)malloc(sizeof(char *) * lemin->vertices)))
		error_exit();
	start = NULL;
	end = NULL;
	i = 0;
	while(rooms)
	{
		if (rooms->is_cmd == 1)
			start = ft_strdup(rooms->name);
		else if (rooms->is_cmd == 2)
			end = ft_strdup(rooms->name);
		lemin->rooms[i] = ft_strdup(rooms->name);
		i++;
		rooms = rooms->next;
	}
	if (!start || !end)
		error_exit();
	ft_qsort(lemin);
	lemin->start = room_num(lemin, start);
	lemin->end = room_num(lemin, end);
	if (lemin->start == -1 || lemin->end == -1)
		error_exit();
}

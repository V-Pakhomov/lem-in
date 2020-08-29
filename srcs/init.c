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

t_room *new_room(char *name)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(name);
	new->next = 0;
	return(new);
}

void add_room(t_room **all_lst, char *name)
{
	t_room *new;

	if (*all_lst != NULL)
	{
		new = new_room(name);
		new->next = *all_lst;
		*all_lst = new;
	}
	else
		*all_lst = new_room(name);
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

char **init_room_names_dict(t_room *rooms, int size)
{
	int i;
	char **output;
	t_room *pointer;

	output = 0;
	pointer = rooms;;

	size++;

	if (!(output = (char **)malloc(sizeof(char *) * (size + 1))))
		ft_printf("lol\n");
	i = 0;
	while(pointer != 0)
	{
		output[i] = ft_strdup(pointer->name);
		i++;
		pointer = pointer->next;
	}
	pointer = 0;
	output[i] = 0;
	return (output);
}

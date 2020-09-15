#include "lemin.h"


void intialize_adjacency_list(t_lemin *lemin, t_link *links)
{
	int i;
	int j;

	if (!(lemin->adj_list = (t_neighbor**)malloc(sizeof(t_neighbor*) * lemin->vertices)))
		error_exit();
	i = 0;
	while (i < lemin->vertices)
		lemin->adj_list[i++] = NULL;
	while(links)
	{
		i = room_num(lemin, links->first);
		j = room_num(lemin, links->last);
		if (i == -1 || j == - 1)
			error_exit();
		add_neighbor(&(lemin->adj_list[i]), j);
		add_neighbor(&(lemin->adj_list[j]), i);
		links = links->next;
	}
}

t_link *new_link(char *first, char *last)
{
	t_link *new;

	if (!(new = (t_link *)malloc(sizeof(t_link))))
		return (0);
	new->first = ft_strdup(first);
	new->last = ft_strdup(last);
	new->next = NULL;
	return(new);
}

t_room *new_room(char **room, int cmd_flag)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(room[0]);
	new->next = 0;
	new->is_cmd = cmd_flag;
	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	return(new);
}

void add_room(t_room **all_lst, char *name, int cmd_flag)
{
	t_room *new;
	char **room;

	room = 0;
	room = ft_strsplit(name, ' ');
	if (*all_lst != NULL)
	{
		new = new_room(room, cmd_flag);
		new->next = *all_lst;
		*all_lst = new;
	}
	else
		*all_lst = new_room(room, cmd_flag);
	ft_arrayfree(room);
}

void add_link(t_link **all_lst, char *first, char *last)
{
	t_link *new;

	if (ft_strequ(first, last))
		return ;
	new = new_link(first, last);
	if (*all_lst == NULL)
	{
		*all_lst = new;
		return ;
	}
	new->next = *all_lst;
	*all_lst = new;
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
	free(start);
	free(end);
}

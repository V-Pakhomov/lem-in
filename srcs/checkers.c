#include "lemin.h"

int is_comment(char *s)
{
	return (s[0] == '#' && s[1] != '#');
}

int is_cmd(char *s)
{
	return (ft_strequ(s, "##start") || ft_strequ(s, "##end"));
}

int is_room(char *s)
{
	int i;
	char **s_for_inspect;

	i = 0;
	s_for_inspect = ft_strsplit(s, ' ');
	if (s_for_inspect[0][0] == '#' || s_for_inspect[0][1] == 'L' || ft_strchr(s_for_inspect[0], '-'))
		return (0);
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

int check_dup_elem(char *line, t_room *rooms)
{
	t_room *ptr;
	char **room;

	room = 0;
	room = ft_strsplit(line, ' ');

	ptr = rooms;
	while(ptr != 0)
	{
		if (ptr->name == room[0] || (ptr->x == ft_atoi(room[1]) && ptr->y == ft_atoi(room[2])))
		{
			ft_arrayfree(room);
			room = 0;
			error_exit();
			return(0);
		}
		ptr = ptr->next;
	}
	ft_arrayfree(room);
	room = 0;
	return(1);
}

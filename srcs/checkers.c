/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:52:11 by rciera            #+#    #+#             */
/*   Updated: 2020/09/21 20:51:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_comment(char *s)
{
	return (s[0] == '#' && !ft_strequ("##start", s) && !ft_strequ("##end", s));
}

int		is_cmd(char *s)
{
	return (ft_strequ(s, "##start") || ft_strequ(s, "##end"));
}

int		is_room(char *s)
{
	char	**s_for_inspect;
	int		res;

	s_for_inspect = ft_strsplit(s, ' ');
	res = 0;
	if (s_for_inspect[0][0] == '#' ||
		s_for_inspect[0][1] == 'L' ||
		ft_strchr(s_for_inspect[0], '-'))
		res = 0;
	else
		res = 1;
	res &= (ft_arraylen(s_for_inspect) == 3);
	if (!res)
	{
		ft_arrayfree(s_for_inspect);
		return (0);
	}
	res &= ft_isinteger(s_for_inspect[1]);
	res &= ft_isinteger(s_for_inspect[2]);
	ft_arrayfree(s_for_inspect);
	return (res);
}

int		is_link(char *s)
{
	char	**s_for_inspect;
	int		res;

	s_for_inspect = ft_strsplit(s, '-');
	res = (ft_arraylen(s_for_inspect) == 2);
	ft_arrayfree(s_for_inspect);
	return (res);
}

int		check_dup_elem(char *line, t_room *rooms, int d_flag)
{
	t_room	*ptr;
	char	**room;

	room = ft_strsplit(line, ' ');
	ptr = rooms;
	while (ptr)
	{
		if (ptr->name == room[0] ||
			(ptr->x == ft_atoi(room[1]) && ptr->y == ft_atoi(room[2])))
		{
			ft_arrayfree(room);
			error_exit(d_flag, "Duplicated room has been found");
		}
		ptr = ptr->next;
	}
	ft_arrayfree(room);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_rooms_and_links.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:00:49 by rciera            #+#    #+#             */
/*   Updated: 2020/09/21 20:34:24 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_link	*new_link(char *first, char *last)
{
	t_link *new;

	if (!(new = (t_link *)malloc(sizeof(t_link))))
		return (0);
	new->first = ft_strdup(first);
	new->last = ft_strdup(last);
	new->next = NULL;
	return (new);
}

void			add_link(t_link **all_lst, char *first, char *last)
{
	t_link	*new;

	new = new_link(first, last);
	if (*all_lst == NULL)
	{
		*all_lst = new;
		return ;
	}
	new->next = *all_lst;
	*all_lst = new;
}

static t_room	*new_room(char **room, int cmd_flag)
{
	t_room	*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(room[0]);
	new->next = NULL;
	new->is_cmd = 0;
	if (cmd_flag & 1)
		new->is_cmd = 1;
	if (cmd_flag & (1 << 1))
		new->is_cmd = 2;
	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	return (new);
}

void			add_room(t_room **all_lst, char *name, int cmd_flag)
{
	t_room	*new;
	char	**room;

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


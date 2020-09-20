/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:52:11 by rciera            #+#    #+#             */
/*   Updated: 2020/09/20 22:35:23 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_links(t_lemin *lemin)
{
	t_link *link;

	link = lemin->links;
	while (link)
	{
		if (room_num(lemin, link->first) == -1 ||
			room_num(lemin, link->last) == -1)
			error_exit();
		if (ft_strequ(link->first, link->last))
			error_exit();
		link = link->next;
	}
}

void	check_repeating_rooms(t_lemin *lemin)
{
	int i;
	t_room *ptr;
	t_room *ptr2;

	i = 1;
	ptr = lemin->rooms_raw;
	while (i < lemin->vertices)
	{
		if (ft_strequ(lemin->rooms[i], lemin->rooms[i - 1]))
			error_exit();
		i++;
	}
	while(ptr != 0)
	{
		ptr2 = ptr->next;
		while(ptr2 != 0)
		{
			if (ptr->x == ptr2->x && ptr->y == ptr2->y)
				error_exit();
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

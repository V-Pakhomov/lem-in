/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:52:11 by rciera            #+#    #+#             */
/*   Updated: 2020/09/22 17:09:02 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_links(t_lemin *lemin, int d_flag)
{
	t_link *link;

	link = lemin->links;
	while (link)
	{
		if (room_num(lemin, link->first) == -1 ||
			room_num(lemin, link->last) == -1)
			error_exit(d_flag, "Error in links");
		if (ft_strequ(link->first, link->last))
			error_exit(d_flag, "Loop link found");
		link = link->next;
	}
}

void	check_repeating_rooms(t_lemin *lemin, int d_flag)
{
	int		i;
	t_room	*ptr;
	t_room	*ptr2;

	i = 1;
	ptr = lemin->rooms_raw;
	while (i < lemin->vertices)
	{
		if (ft_strequ(lemin->rooms[i], lemin->rooms[i - 1]))
			error_exit(d_flag, "Found repeating rooms");
		i++;
	}
	while (ptr != 0)
	{
		ptr2 = ptr->next;
		while (ptr2 != 0)
		{
			if (ptr->x == ptr2->x && ptr->y == ptr2->y)
				error_exit(d_flag, "Found repeating ccordinates");
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

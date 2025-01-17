/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:25:44 by rciera            #+#    #+#             */
/*   Updated: 2020/10/14 17:30:16 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	printable(t_lemin *lemin, int line)
{
	t_path	*tmp;
	int		i;
	int		was_printed;

	was_printed = 0;
	tmp = lemin->path;
	while (tmp)
	{
		i = 0;
		while (i < tmp->ants)
		{
			if (line - i >= 0 && line - i < tmp->len)
			{
				was_printed = 1;
				ft_printf("L%d-%s ", tmp->first_ant + i,
							lemin->rooms[tmp->path[line - i]]);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (was_printed);
}

void		prnt_lst_links(t_link *links)
{
	t_link *ptr;

	ptr = links;
	while (ptr != 0)
	{
		ft_printf("%s-%s\n", ptr->first, ptr->last);
		ptr = ptr->next;
	}
}

void		prnt_lst_rooms(t_room *rooms)
{
	t_room *ptr;

	ptr = rooms;
	while (ptr)
	{
		if (ptr->is_cmd == 1)
			ft_printf("##start\n");
		else if (ptr->is_cmd == 2)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", ptr->name, ptr->x, ptr->y);
		ptr = ptr->next;
	}
}

void		print_output(t_lemin *lemin)
{
	int line;

	p_input(lemin->input_raw);
	line = 0;
	while (printable(lemin, line++))
		ft_printf("\n");
	exit(0);
}

void		start_and_finish_are_connected(t_lemin *lemin)
{
	int i;

	ft_printf("%d\n", lemin->ants);
	prnt_lst_rooms(lemin->rooms_raw);
	prnt_lst_links(lemin->links);
	i = 1;
	while (i <= lemin->ants)
		ft_printf("L%d-%s ", i++, lemin->rooms[lemin->end]);
	ft_putendl("");
	exit(0);
}

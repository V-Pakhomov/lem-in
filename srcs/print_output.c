/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:25:44 by rciera            #+#    #+#             */
/*   Updated: 2020/08/28 16:50:32 by rciera           ###   ########.fr       */
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

void		print_output(t_lemin *lemin)
{
	int line;

	line = 0;
	while (printable(lemin, line++))
		ft_printf("\n");
}

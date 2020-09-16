/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_helpful.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:57:06 by rciera            #+#    #+#             */
/*   Updated: 2020/09/16 18:58:14 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_matrix(int **m, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_printf("%d  ", m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_links(t_link *links)
{
	t_link *l;

	l = links;
	while (l != 0)
	{
		ft_printf("%s  --  %s\n", l->first, l->last);
		l = l->next;
	}
}

void	print_lst_of_rooms(char **rooms)
{
	int i;

	i = 0;
	while (rooms[i] != 0)
	{
		ft_printf("[%d : %s]\n", i, rooms[i]);
		i++;
	}
}

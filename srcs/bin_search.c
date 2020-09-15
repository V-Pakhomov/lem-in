/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:53:13 by rciera            #+#    #+#             */
/*   Updated: 2020/09/15 15:51:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int room_num(t_lemin *lemin, char *key)
{
	int l;
	int m;
	int r;

	l = 0;
	r = lemin->vertices;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (ft_strcmp(lemin->rooms[m], key) <= 0)
			l = m;
		else
			r = m;
	}
	if (ft_strcmp(lemin->rooms[l], key))
		return (-1);
	return (l);
}

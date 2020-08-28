/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:53:13 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 19:14:31 by rciera           ###   ########.fr       */
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
	return (l);
}

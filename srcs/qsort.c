/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:41:51 by rciera            #+#    #+#             */
/*   Updated: 2020/09/16 16:47:20 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	recoursive(t_lemin *lemin, int left, int right)
{
	int		l;
	int		r;
	char	*m;
	char	*tmp;

	if (left >= right)
		return ;
	m = lemin->rooms[(left + right) / 2];
	l = left;
	r = right;
	while (r > l)
	{
		while (ft_strcmp(lemin->rooms[l], m) < 0)
			l++;
		while (ft_strcmp(lemin->rooms[r], m) > 0)
			r--;
		if (r >= l)
		{
			tmp = lemin->rooms[l];
			lemin->rooms[l++] = lemin->rooms[r];
			lemin->rooms[r--] = tmp;
		}
	}
	recoursive(lemin, left, r);
	recoursive(lemin, l, right);
}

void		ft_qsort(t_lemin *lemin)
{
	recoursive(lemin, 0, lemin->vertices - 1);
}

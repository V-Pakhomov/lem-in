/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:41:51 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 17:38:30 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void recoursive(char ***rooms, int left, int right, int arr_size)
{
	char *m;
	int l;
	int r;
	char *tmp;

	if (left >= right)
		return;
	m = (*rooms)[(left + right) / 2];
	l = left;
	r = right;
	while (r > l)
	{
		while (ft_strcmp((*rooms)[l], m) < 0)
			l++;
		while (ft_strcmp((*rooms)[r], m) > 0)
			r--;
		if (r >= l)
		{
			tmp = (*rooms)[l];
			(*rooms)[l] = (*rooms)[r];
			(*rooms)[r] = tmp;
			l++;
			r--;
		}
	}
	recoursive(rooms, left, r, arr_size);
	recoursive(rooms, l, right, arr_size);
}

void ft_qsort(char ***rooms, int arr_size)
{
	recoursive(rooms, 0, arr_size - 1, arr_size);
}
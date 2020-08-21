/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:53:13 by rciera            #+#    #+#             */
/*   Updated: 2020/08/21 14:18:49 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int room_num(char **rooms, int size, char *key)
{
	int l;
	int m;
	int r;

	l = 0;
	r = size;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (ft_strcmp(rooms[m], key) <= 0)
			l = m;
		else
			r = m;
	}
	return (l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_paths_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:20:42 by rciera            #+#    #+#             */
/*   Updated: 2020/08/26 17:06:50 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path *new_path(t_lemin *lemin)
{
	t_path *new;
	int i;
	int vert;
	int len;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		error_exit();
	if (!(new->path = (int*)malloc(sizeof(int) * len)))
		error_exit();
	len = lemin->path_len[lemin->end];
	new->ants = 0;
	new->len = len;
	new->next = NULL;
	vert = lemin->end;
	i = 0;
	while (i < len)
	{
		new->path[len - i - 1] = vert;
		vert = lemin->parent[vert];
		i++;
	}
	return (new);
}

void	push_path(t_lemin *lemin, t_path *new)
{
	t_path *tmp;

	if (!lemin->path)
	{
		lemin->path = new;
		return ;
	}
	tmp = lemin->path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void refresh_paths(t_lemin *lemin)
{
	int max_path;

	lemin->num_of_paths++;
	max_path = lemin->path_len[lemin->end] + 1;
	push_path(lemin, new_path(lemin));

}

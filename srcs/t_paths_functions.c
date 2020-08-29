/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_paths_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:20:42 by rciera            #+#    #+#             */
/*   Updated: 2020/08/28 15:00:50 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	*new_path(t_lemin *lemin)
{
	t_path	*new;
	int		i;
	int		vert;
	int		len;

	len = lemin->path_len[lemin->end];
	if (!(new = (t_path*)malloc(sizeof(t_path))))
		error_exit();
	if (!(new->path = (int*)malloc(sizeof(int) * len)))
		error_exit();
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

void			set_num_of_first_ant(t_lemin *lemin)
{
	int		first_ant;
	t_path	*tmp;

	tmp = lemin->path;
	first_ant = 1;
	while (tmp)
	{
		tmp->first_ant = first_ant;
		first_ant += tmp->ants;
		tmp = tmp->next;
	}
}

void			set_ants_to_paths(t_lemin *lemin, int max_path_len)
{
	t_path	*tmp;
	int		ants;
	int		diff;
	int		mod;

	tmp = lemin->path;
	ants = lemin->ants;
	while (tmp)
	{
		tmp->ants = max_path_len - tmp->len + 1;
		ants -= tmp->ants;
		tmp = tmp->next;
	}
	tmp = lemin->path;
	diff = ants / lemin->num_of_paths;
	mod = ants % lemin->num_of_paths;
	while (tmp)
	{
		tmp->ants += mod ? diff + 1 : diff;
		mod -= mod ? 1 : 0;
		tmp = tmp->next;
	}
	set_num_of_first_ant(lemin);
}

static void		push_path(t_lemin *lemin, t_path *new)
{
	t_path	*tmp;

	if (!lemin->path)
	{
		lemin->path = new;
		lemin->path->ants = lemin->ants;
		lemin->path->first_ant = 1;
		return ;
	}
	tmp = lemin->path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	set_ants_to_paths(lemin, new->len);
}

void			refresh_paths(t_lemin *lemin)
{
	int max_path;

	lemin->num_of_paths++;
	max_path = lemin->path_len[lemin->end] + 1;
	push_path(lemin, new_path(lemin));
}

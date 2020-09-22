/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_addition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:00:49 by rciera            #+#    #+#             */
/*   Updated: 2020/09/22 17:12:49 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_input	*new_input(char *line)
{
	t_input *new;

	if (!(new = (t_input *)malloc(sizeof(t_input))))
		return (0);
	new->line = ft_strdup(line);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			add_input(t_input **all_input, char *line)
{
	t_input	*new;

	new = new_input(line);
	if (*all_input == NULL)
	{
		*all_input = new;
		return ;
	}
	new->next = *all_input;
	(*all_input)->prev = new;
	*all_input = new;
}

void			p_input(t_input *in)
{
	t_input	*p;

	p = in;
	while (p->next != 0)
	{
		p = p->next;
	}
	while (p != 0)
	{
		ft_printf("%s\n", p->line);
		p = p->prev;
	}
	ft_printf("\n");
}

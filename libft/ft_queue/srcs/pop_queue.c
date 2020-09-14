/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:21:40 by rciera            #+#    #+#             */
/*   Updated: 2020/09/02 18:28:28 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	pop_queue(t_queue **q)
{
	t_queue *tmp;

	tmp = *q;
	if (!tmp)
		return ;
	tmp = tmp->next;
	free(*q);
	*q = tmp;
}
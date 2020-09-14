/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:21:49 by rciera            #+#    #+#             */
/*   Updated: 2020/09/14 14:46:18 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

long long	back_queue(t_queue **q)
{
	t_queue *tmp;

	tmp = *q;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->num);
}

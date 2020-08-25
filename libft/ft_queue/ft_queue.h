/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:45:28 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 15:52:08 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

#include "stddef.h"

typedef struct	s_queue
{
	long long		num;
	struct s_queue	*next;
	struct s_queue	*prev;
}				t_queue;

void			push_queue(t_queue **q, long long n);
void			pop_queue(t_queue **q);
long long		front_queue(t_queue **q);
long long		back_queue(t_queue **q);
int				empty_queue(t_queue *q);

#endif
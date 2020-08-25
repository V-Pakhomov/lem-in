/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:23:16 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 19:15:44 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "ft_queue.h"

typedef struct	s_path
{
	int				ants;
	int				len;
	int				*path;
	struct s_path	*next;
}				t_path;

typedef struct	s_lemin
{
	int		ants_num;
	int		vertices;
	char	**rooms;
	int		**adj_matrix;
	int		*used;
	int		*parent;
	int		*path_len;
	t_path	*path;
}				t_lemin;

/*
** qsort.c
*/
void			ft_qsort(t_lemin *lemin);

/*
** bin_search
*/
int				room_num(t_lemin *lemin, char *key);

#endif

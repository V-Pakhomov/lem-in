/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:23:16 by rciera            #+#    #+#             */
/*   Updated: 2020/08/26 17:07:41 by rciera           ###   ########.fr       */
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
	int		start;
	int		end;
	int		ants;
	int		vertices;
	char	**rooms;
	int		**adj_matrix;
	int		*used;
	int		*parent;
	int		*path_len;
	int		max_path_len;
	int 	num_of_paths;
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

/*
** 	error.c
*/
void			error_exit(void);

/*
** t_path_functions.c
*/
void			push_path(t_lemin *lemin, t_path *new);

/*
** bfs.c
*/
void			bfs(t_lemin *lemin);

#endif

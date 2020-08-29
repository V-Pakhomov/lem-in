/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:23:16 by rciera            #+#    #+#             */
/*   Updated: 2020/08/29 16:41:44 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "ft_queue.h"

typedef struct	s_path
{
	int				first_ant;
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


typedef struct s_link
{
	char *first;
	char *last;
	struct s_link *next;
}				t_link;


typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
	int		is_cmd;			//1 - start, 2 - end
	struct	s_room *next;

}				t_room;


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
void			refresh_paths(t_lemin *lemin);

/*
** bfs.c
*/
void			bfs(t_lemin *lemin);

/*
** edmonds_karp.c
*/
void		edmonds_karp(t_lemin *lemin);

/*
** file_to_debug.c
*/
void	debug_print_rooms(t_lemin *lemin);
void	print_adj_matrix(t_lemin *lemin);
void	print_paths(t_lemin *lemin);
void	print_lemin(t_lemin *lemin);

/*
** print_output.c
*/
void		print_output(t_lemin *lemin);
void		start_and_finish_are_connected(t_lemin *lemin);






/*
** validation and input parsing
** TO DO: refactor and sort
*/
int **intialize_adjacency_matrix(int size);
t_link *new_link(char *first, char *last);
t_room *new_room(char *name, int cmd_flag);
void add_room(t_room **all_lst, char *name, int cmd_flag);
void add_link(t_link **all_lst, char *first, char *last);

int is_comment(char *s);
int is_cmd(char *s);
int is_room(char *s);
int is_link(char *s);
t_lemin *parse_input(void);

void print_matrix(int **m, int size);
void print_links(t_link *links);
void print_rooms(t_room *rooms);
void print_lst_of_rooms(char **rooms);

char **init_room_names_dict(t_room *rooms, t_lemin *lemin);



#endif

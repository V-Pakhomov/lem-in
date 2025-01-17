/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:23:16 by rciera            #+#    #+#             */
/*   Updated: 2020/09/22 17:07:24 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

typedef struct	s_path
{
	int				first_ant;
	int				ants;
	int				len;
	int				*path;
	struct s_path	*next;
}				t_path;

typedef struct	s_link
{
	char			*first;
	char			*last;
	struct s_link	*next;
}				t_link;

/*
** is_cmd
** 1 - start
** 2 - end
*/
typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				is_cmd;
	struct s_room	*next;

}				t_room;

typedef struct	s_input
{
	char			*line;
	struct s_input	*next;
	struct s_input	*prev;
}				t_input;

typedef struct	s_neighbor
{
	int					room;
	struct s_neighbor	*next;
}				t_neighbor;

typedef struct	s_lemin
{
	int			start;
	int			end;
	int			ants;
	int			vertices;
	char		**rooms;
	t_neighbor	**adj_list;
	int			*used;
	int			*parent;
	int			*path_len;
	int			max_path_len;
	int			num_of_paths;
	t_path		*path;
	t_link		*links;
	t_room		*rooms_raw;
	t_input		*input_raw;
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
void			error_exit(int d_flag, char *s);

/*
** t_path_functions.c
*/
void			refresh_paths(t_lemin *lemin, int d_flag);

/*
** bfs.c
*/
void			bfs(t_lemin *lemin);

/*
** edmonds_karp.c
*/
void			edmonds_karp(t_lemin *lemin, int d_flag);

/*
** file_to_debug.c
*/
void			print_rooms(t_lemin *lemin);
void			print_adj_list(t_lemin *lemin);
void			print_paths(t_lemin *lemin);
void			print_lemin(t_lemin *lemin);
void			print_bfs_info(t_lemin *lemin);

/*
** print_output.c
*/
void			print_output(t_lemin *lemin);
void			start_and_finish_are_connected(t_lemin *lemin);
void			prnt_lst_rooms(t_room *rooms);

/*
** t_neighbors.c
*/
void			add_neighbor(t_neighbor **neighbor, int n, int flag_d);
void			delete_neighbor(t_neighbor **neighbor, int n);
int				is_neighbor(t_lemin *lemin, int n, int m);

/*
** validation and input parsing
** TO DO: refactor and sort
*/
void			intialize_adjacency_list(t_lemin *lemin, int d_flag);
void			add_room(t_room **all_lst, char *name, int cmd_flag);
void			add_link(t_link **all_lst, char *first, char *last);
void			add_input(t_input **all_input, char *line);

int				is_comment(char *s);
int				is_cmd(char *s);
int				is_room(char *s);
int				is_link(char *s);
void			parse_input(t_lemin *lemin, int d_flag);

void			print_matrix(int **m, int size);
void			print_links(t_link *links);
void			print_lst_of_rooms(char **rooms);

void			init_room_names_dict(t_lemin *lemin, int d_flag);
int				check_dup_elem(char *line, t_room *rooms, int d_flag);

t_lemin			*lemin_init(int d_flag);
void			check_links(t_lemin *lemin, int d_flag);
void			check_repeating_rooms(t_lemin *lemin, int d_flag);
void			p_input(t_input *in);

#endif

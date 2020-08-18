#ifndef INPUT_H
# define INPUT_H

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
	struct	s_room *next;

}				t_room;


int **intialize_adjacency_matrix(int size);
t_link *new_link(char *first, char *last);
t_room *new_room(char *name);
void add_room(t_room **all_lst, char *name);
void add_link(t_link **all_lst, char *first, char *last);

int is_comment(char *s);
int is_cmd(char *s);
int is_room(char *s);
int is_link(char *s);
void input(char *filename);

void print_matrix(int **m, int size);
void print_links(t_link *links);
void print_rooms(t_room *rooms);
#endif

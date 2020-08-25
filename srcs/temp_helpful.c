#include "lemin.h"
#include "input.h"

void print_matrix(int **m, int size)
{
	int i = 0;
	int j = 0;

	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			ft_printf("%d  ", m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void print_links(t_link *links)
{
	t_link *l = 0;
	l = links;
	while(l->next != 0)
	{
		ft_printf("%s  --  %s\n", l->first, l->last);
		l = l->next;
	}
}


void print_rooms(t_room *rooms)
{
	t_room *l = 0;
	l = rooms;
	while(l->next != 0)
	{
		ft_printf("Room: %s\n", l->name);
		l = l->next;
	}
}

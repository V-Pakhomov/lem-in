#include "/Users/admin/school_21/lemin/libft/libft.h"
#include "input.h"

int is_comment(char *s)
{
	int i;

	i = 0;
	if (s[i] == '#' && s[i + 1] != '#')
		return (1);
	return (0);
}

int is_cmd(char *s)
{
	int i;
	i = 0;

	char *cmd_start = "##start";
	char *cmd_end = "##end";
	if (ft_strcmp(cmd_start, s) || ft_strcmp(cmd_end, s))
		return (1);
	return(0);
}

int is_room(char *s)
{
	int i;
	char **s_for_inspect;

	i = 0;
	s_for_inspect = ft_strsplit(s, ' ');
	if (ft_arraylen(s_for_inspect) == 3 && ft_isinteger(s_for_inspect[1]) && ft_isinteger(s_for_inspect[2]))
		return (1);
	return (0);
}


int is_link(char *s)
{
	int i;
	char **s_for_inspect;

	i = 0;
	s_for_inspect = ft_strsplit(s, '-');
	if (ft_arraylen(s_for_inspect) == 2)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:13:49 by rciera            #+#    #+#             */
/*   Updated: 2019/09/28 20:09:55 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	remalloc(char **line, size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(size)))
		return ;
	tmp = ft_strcpy(tmp, *line);
	free(*line);
	*line = tmp;
}

static char	*add_to_line(char **line, char *buff, size_t *line_size)
{
	size_t	size;
	char	*substr;

	size = 0;
	while (buff[size] && buff[size] != '\n')
		size++;
	*line_size += size;
	if (size != 0)
	{
		remalloc(line, *line_size);
		substr = ft_strsub(buff, 0, size);
		*line = ft_strcat(*line, substr);
		free(substr);
	}
	return (ft_strdup(ft_strchr(buff, '\n')));
}

static int	first_blood(char **beg_of_line, char **line, size_t *line_size)
{
	char *copy;

	if (*beg_of_line && ft_strlen(*beg_of_line) != 0)
	{
		copy = ft_strdup(*beg_of_line + 1);
		free(*beg_of_line);
		*beg_of_line = add_to_line(line, copy, line_size);
		free(copy);
		if (*beg_of_line != NULL)
			return (1);
	}
	return (0);
}

static int	out(char **line, char **beg_of_line)
{
	if (ft_strlen(*line) == 0 && *beg_of_line == NULL)
	{
		free(*line);
		free(*beg_of_line);
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	ssize_t		res;
	size_t		line_size;
	static char	*beg_of_line[1024];

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0 ||
		BUFF_SIZE < 1 || !(*line = (char *)malloc(1)))
		return (-1);
	ft_strclr(*line);
	line_size = 1;
	if (first_blood(&(beg_of_line[fd]), line, &line_size) == 1)
		return (1);
	beg_of_line[fd] = NULL;
	res = read(fd, buff, BUFF_SIZE);
	buff[res] = '\0';
	beg_of_line[fd] = add_to_line(line, buff, &line_size);
	while (res == BUFF_SIZE && beg_of_line[fd] == NULL)
	{
		ft_strclr(buff);
		res = read(fd, buff, BUFF_SIZE);
		beg_of_line[fd] = add_to_line(line, buff, &line_size);
	}
	return (out(line, &(beg_of_line[fd])));
}

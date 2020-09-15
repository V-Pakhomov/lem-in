/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:13:49 by rciera            #+#    #+#             */
/*   Updated: 2020/09/15 15:57:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	remalloc(char **line, size_t size)
// {
// 	char	*tmp;

// 	if (!(tmp = (char *)malloc(size)))
// 		return ;
// 	tmp = ft_strcpy(tmp, *line);
// 	free(*line);
// 	*line = tmp;
// }

// static char	*add_to_line(char **line, char *buff, size_t *line_size)
// {
// 	size_t	size;
// 	char	*substr;

// 	size = 0;
// 	while (buff[size] && buff[size] != '\n')
// 		size++;
// 	*line_size += size;
// 	if (size != 0)
// 	{
// 		remalloc(line, *line_size);
// 		substr = ft_strsub(buff, 0, size);
// 		*line = ft_strcat(*line, substr);
// 		free(substr);
// 	}
// 	return (ft_strdup(ft_strchr(buff, '\n')));
// }

// static int	first_blood(char **beg_of_line, char **line, size_t *line_size)
// {
// 	char *copy;

// 	if (*beg_of_line && ft_strlen(*beg_of_line) != 0)
// 	{
// 		copy = ft_strdup(*beg_of_line + 1);
// 		free(*beg_of_line);
// 		*beg_of_line = add_to_line(line, copy, line_size);
// 		free(copy);
// 		if (*beg_of_line != NULL)
// 			return (1);
// 	}
// 	return (0);
// }

// static int	out(char **line, char **beg_of_line)
// {
// 	if (ft_strlen(*line) == 0 && *beg_of_line == NULL)
// 	{
// 		free(*line);
// 		free(*beg_of_line);
// 		return (0);
// 	}
// 	return (1);
// }

// int			get_next_line(const int fd, char **line)
// {
// 	char		buff[BUFF_SIZE + 1];
// 	ssize_t		res;
// 	size_t		line_size;
// 	static char	*beg_of_line[1024];

// 	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0 ||
// 		BUFF_SIZE < 1 || !(*line = (char *)malloc(1)))
// 		return (-1);
// 	ft_strclr(*line);
// 	line_size = 1;
// 	if (first_blood(&(beg_of_line[fd]), line, &line_size) == 1)
// 		return (1);
// 	beg_of_line[fd] = NULL;
// 	res = read(fd, buff, BUFF_SIZE);
// 	buff[res] = '\0';
// 	beg_of_line[fd] = add_to_line(line, buff, &line_size);
// 	while (res == BUFF_SIZE && beg_of_line[fd] == NULL)
// 	{
// 		ft_strclr(buff);
// 		res = read(fd, buff, BUFF_SIZE);
// 		beg_of_line[fd] = add_to_line(line, buff, &line_size);
// 	}
// 	return (out(line, &(beg_of_line[fd])));
// }


/*
** Finds the position of the newline char in the string that is passed to it
*/

static size_t	find_n(char **str, const int fd)
{
	size_t	i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	return (i);
}

/*
** Takes the static var `str` and appends the string to `line` without the '\n'
** char. Adds the overflow text to `extra` to temp hold the text before
** reassigning it to static var `str` for use in the next loop.
*/

static int		newline(const int fd, char **line, int ret, char **str)
{
	char	*extra;
	size_t	i;

	i = find_n(str, fd);
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		extra = ft_strdup(str[fd] + 1 + i);
		free(str[fd]);
		str[fd] = extra;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

/*
** Function to determine what number (-1, 0, 1) to pass back to the main
** -1 for an error, 0 for completion of reading in GNL, 1 for a successful
** read of a line. Calls newline func to perform its job of reading to line
** We are only assumed to be finished reading when the return value is 0 AND
** the substring is at position '\0'
*/

static int		result(int ret, char **str, const int fd, char **line)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd] == 0))
		return (0);
	return (newline(fd, line, ret, str));
}

/*
** ! Assumed `**line` will be initialized and freed by the main !
** Multiple FDs supported. BUFF_SIZE chars are read from the FD, and assigned
** to a temp variable, by joining `str` and `buffer`, before reassigning to
** static var for safe-keeping. If a newline char is found in `buffer` during
** the loop, we break out of the loop and call the newline function for
** handling of assigning the "line" to `**line` for use in the main.
*/

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char *str[99];
	char		*tmp;

	if (fd < 0 || line == NULL || read(fd, buffer, 0))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (str[fd] == NULL)
			str[fd] = ft_strdup("");
		buffer[ret] = '\0';
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (result(ret, str, fd, line));
}

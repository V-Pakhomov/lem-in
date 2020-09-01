/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:10:50 by rciera            #+#    #+#             */
/*   Updated: 2019/12/03 15:24:59 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	words_count(const char *s, char c)
{
	size_t count;
	size_t i;

	if (!s || !s[0])
		return (0);
	count = 0;
	i = 0;
	while (s[i + 1])
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		i++;
	}
	if (s[i] != c)
		count++;
	return (count);
}

static void		beglen(const char *s, char c, int **beg, int **len)
{
	size_t i;
	size_t j;
	size_t size;

	size = words_count(s, c);
	if (size == 0)
		return ;
	j = 0;
	if (s[0] && s[0] != c)
	{
		(*beg)[j] = 0;
		if (!s[1])
			(*len)[j] = 1;
	}
	i = 0;
	while (s[++i])
	{
		if (s[i - 1] == c && s[i] != c)
			(*beg)[j] = i;
		if ((s[i] == c && s[i - 1] != c) || (s[i] != c && !s[i + 1]))
		{
			(*len)[j] = i - (*beg)[j] + (s[i] != c);
			j++;
		}
	}
}

static void		free_arrays(int **beg, int **len, char ***arr, size_t arr_size)
{
	size_t i;

	i = 0;
	while (i < arr_size)
		free((*arr)[i++]);
	free(beg);
	free(len);
}

static int		give_me_memory(char ***arr, int **beg, int **len, size_t size)
{
	if (size + 1 == 0)
		return (0);
	if (!(*beg = (int*)malloc(sizeof(int) * size)))
		return (0);
	if (!(*len = (int*)malloc(sizeof(int) * size)))
	{
		free(*beg);
		return (0);
	}
	if (!(*arr = (char**)malloc(sizeof(char*) * (size + 1))))
	{
		free(*beg);
		free(*len);
		return (0);
	}
	return (1);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	size;
	char	**arr;
	int		*beg;
	int		*len;
	size_t	i;

	size = words_count(s, c);
	if (give_me_memory(&arr, &beg, &len, size) == 0)
		return (NULL);
	beglen(s, c, &beg, &len);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_strsub(s, beg[i], len[i]);
		if (arr[i] == NULL)
			free_arrays(&beg, &len, &arr, i);
		i++;
	}
	arr[i] = 0;
	free(beg);
	free(len);
	return (arr);
}

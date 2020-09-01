/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:18:57 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 20:05:34 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	istrash(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = len - 1;
	while (istrash(s[i]))
	{
		len--;
		if (i == 0)
			break ;
		i--;
	}
	i = 0;
	while (i < len && istrash(s[i]))
	{
		len--;
		i++;
	}
	str = ft_strsub(s, i, len);
	return (str);
}

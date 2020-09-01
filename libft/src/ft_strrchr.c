/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:11:10 by rciera            #+#    #+#             */
/*   Updated: 2019/09/09 21:13:04 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last;
	char	*str;

	str = (char*)s;
	i = 0;
	last = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last = i;
		i++;
	}
	if (str[i] == (char)c)
		last = i;
	if (str[last] == (char)c)
		return (&str[last]);
	return (NULL);
}

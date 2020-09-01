/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:19:14 by rciera            #+#    #+#             */
/*   Updated: 2019/09/12 20:11:39 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;
	char	*s1;

	s1 = (char*)str1;
	if (!str2[0])
		return (s1);
	i = 0;
	while (str1[i])
	{
		while (str1[i] && str1[i] != str2[0])
			i++;
		if (!str1[i])
			return (NULL);
		j = i;
		while (str2[j - i] && str1[j] && str2[j - i] == str1[j])
			j++;
		if (!str2[j - i])
			return (&(s1[i]));
		i++;
	}
	return (NULL);
}

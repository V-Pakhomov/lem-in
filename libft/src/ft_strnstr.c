/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:44:43 by rciera            #+#    #+#             */
/*   Updated: 2019/09/12 20:08:49 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	char *s;

	s = ft_strstr(ft_strsub(str1, 0, len), str2);
	if (s != NULL)
		return (ft_strstr(str1, s));
	return (NULL);
}

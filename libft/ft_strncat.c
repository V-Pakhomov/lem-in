/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:33:55 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/21 13:37:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = str1;
	while (*str1 != '\0' && *str1 != '\n')
		str1++;
	i = 0;
	while (i < n && str2[i])
	{
		*str1 = str2[i];
		str1++;
		i++;
	}
	*str1 = '\0';
	return (tmp);
}

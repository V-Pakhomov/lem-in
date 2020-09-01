/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:19:17 by rciera            #+#    #+#             */
/*   Updated: 2020/07/29 21:47:51 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len;
	size_t i;

	len = ft_strlen(s1);
	i = len;
	while (s2[i - len] != '\0')
	{
		s1[i] = s2[i - len];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:50:50 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 19:12:52 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strclr(char *s)
{
	size_t len;
	size_t i;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
		s[i++] = '\0';
}
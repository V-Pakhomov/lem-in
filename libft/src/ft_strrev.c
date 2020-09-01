/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:04:45 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 20:58:32 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrev(char *str)
{
	size_t i;
	size_t len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		ft_swap(&(str[i]), &(str[len - i - 1]));
		i++;
	}
	return (str);
}

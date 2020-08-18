/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:50:06 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/27 17:27:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}

int		ft_strchri(char *s, char c)
{
	int		i;

	i = -1;
	while (s && s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

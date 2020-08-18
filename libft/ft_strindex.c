/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:50:51 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/21 13:36:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strindex(char *haystack, char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		n = i;
		while (needle[j] == haystack[n])
		{
			if (needle[j + 1] == '\0')
				return (i);
			n++;
			j++;
		}
		i++;
	}
	return (-1);
}

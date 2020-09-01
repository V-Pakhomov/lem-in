/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:35:04 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:18 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static char	*numcat(t_arg **arg, long double db,
							char **int_str, char **fract_str)
{
	char	*res;
	int		i;

	res = (char*)malloc((*arg)->precision + ft_strlen(*int_str) + (db < 0) + 2);
	if (!res)
		return (NULL);
	res[0] = '\0';
	res[1] = '\0';
	if (db < 0 || 1 / db == 1 / -0.)
		res[0] = '-';
	res = ft_strcat(res, *int_str);
	res = ft_strcat(res, ".");
	i = ft_strlen(*fract_str);
	while (i < (*arg)->precision)
	{
		res = ft_strcat(res, "0");
		i++;
	}
	res = ft_strcat(res, *fract_str);
	free(*int_str);
	free(*fract_str);
	return (res);
}

char		*ft_dtoa(t_printf *pf, t_arg **arg, long double db)
{
	long double	fract_part;
	char		*fract_str;
	char		*int_str;
	int			i;

	if (!(*arg)->precision)
	{
		if (1 / db == 1 / -0.)
			return (ft_strdup("-0"));
		return (ft_itoa((long long)db));
	}
	fract_part = (db - (long long)db) * (db < 0 ? -1. : 1.);
	i = 0;
	while (i < (*arg)->precision)
	{
		fract_part *= 10.;
		i++;
	}
	fract_str = ft_ulltoa((unsigned long long)(fract_part + 0.5));
	int_str = ft_itoa(ft_abs((long long)db));
	if (!fract_str || !int_str)
		return (null_error(pf));
	return (numcat(arg, db, &int_str, &fract_str));
}

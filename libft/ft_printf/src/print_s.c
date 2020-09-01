/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:54:06 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:52 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	s_precision(t_printf *pf, t_arg **arg)
{
	int		len;
	char	*tmp_out;

	len = ft_strlen((*arg)->out);
	if ((*arg)->precision >= len)
		return (1);
	tmp_out = ft_strsub((*arg)->out, 0, (*arg)->precision);
	if (!tmp_out)
		return (error(pf));
	free((*arg)->out);
	(*arg)->out = tmp_out;
	return (1);
}

int			print_s(t_printf *pf, t_arg **arg)
{
	char	*s;
	int		no_err;

	no_err = 1;
	s = (char *)va_arg(pf->ap, char *);
	if (!s)
		(*arg)->out = ft_strdup("(null)");
	else
		(*arg)->out = ft_strdup(s);
	if (!(*arg)->out)
		no_err = 0;
	if (ft_strchr((*arg)->arg, '.'))
		no_err &= s_precision(pf, arg);
	no_err &= set_field_width(pf, arg);
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}

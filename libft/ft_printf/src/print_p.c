/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:54:02 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:49 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	double_zero(t_printf *pf, t_arg **arg, int no_err)
{
	free((*arg)->out);
	(*arg)->out = ft_strdup("0x");
	(*arg)->out_len = ft_strlen((*arg)->out);
	no_err &= set_field_width(pf, arg);
	return (no_err);
}

int			print_p(t_printf *pf, t_arg **arg)
{
	unsigned long long	p;
	int					no_err;
	char				*tmp;

	no_err = 1;
	p = (unsigned long long)va_arg(pf->ap, unsigned long long);
	(*arg)->out = ft_itoa_base(p, 16);
	if (!(*arg)->out)
		return (error(pf));
	if (!p && !(*arg)->precision)
		return (double_zero(pf, arg, no_err));
	no_err &= set_precision(pf, arg);
	tmp = ft_strjoin("0x", (*arg)->out);
	if (!tmp)
		return (error(pf));
	free((*arg)->out);
	(*arg)->out = tmp;
	no_err &= set_field_width(pf, arg);
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:19:30 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:43 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int			number_sign_handler(t_printf *pf, t_arg **arg)
{
	char *tmp_out;

	if ((*arg)->precision)
		return (1);
	tmp_out = ft_strjoin((*arg)->out, ".");
	if (!tmp_out)
		return (error(pf));
	free((*arg)->out);
	(*arg)->out = tmp_out;
	return (1);
}

static long double	db_round(t_printf *pf, t_arg **arg, long double d)
{
	long double	fract_part;
	int			i;

	if (d < 0 || 1 / d == 1 / -0.)
		return (db_round(pf, arg, d * -1.) * -1.);
	fract_part = d - (unsigned long long)d;
	i = 0;
	while (i < (*arg)->precision)
	{
		fract_part *= 10.;
		i++;
	}
	if (fract_part == 0.5)
	{
		if ((unsigned long long)d % 2)
			d += 1;
		return ((unsigned long long)d);
	}
	fract_part = (unsigned long long)(fract_part + 0.5);
	while (i)
	{
		fract_part /= 10.;
		i--;
	}
	return (unsigned long long)d * 1. + fract_part;
}

static int			length_handler(t_printf *pf, t_arg **arg)
{
	long double db;

	if (!ft_strcmp((*arg)->length_modifier, "L"))
	{
		db = (long double)va_arg(pf->ap, long double);
		if (!nan_inf(pf, arg, db))
			db = db_round(pf, arg, db);
	}
	else
	{
		db = (double)va_arg(pf->ap, double);
		if (!nan_inf(pf, arg, db))
			db = (double)db_round(pf, arg, db);
	}
	if (!((*arg)->out_len))
		(*arg)->out = ft_dtoa(pf, arg, db);
	if (!(*arg)->out)
		return (0);
	return (1);
}

int					print_f(t_printf *pf, t_arg **arg)
{
	int no_err;

	(*arg)->out_len = 0;
	no_err = 1;
	no_err &= length_handler(pf, arg);
	if ((*arg)->out_len)
		return (no_err);
	if ((*arg)->flags.number_sign)
		number_sign_handler(pf, arg);
	if ((*arg)->flags.plus)
		no_err &= add_plus_flag(pf, arg);
	if ((*arg)->flags.space && (*arg)->flags.minus)
	{
		no_err &= add_space_flag(pf, arg);
		no_err &= set_field_width(pf, arg);
	}
	else
	{
		no_err &= set_field_width(pf, arg);
		if ((*arg)->flags.space)
			no_err &= add_space_flag(pf, arg);
	}
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}

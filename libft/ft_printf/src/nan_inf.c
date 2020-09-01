/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:38:46 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:30 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static void	nan(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	(*arg)->out = ft_strdup("nan");
	no_err &= (*arg)->out != NULL;
	no_err &= set_field_width(pf, arg);
	if (!no_err)
		pf->err = 1;
	else
		(*arg)->out_len = ft_strlen((*arg)->out);
}

static void	plus_inf(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	(*arg)->out = ft_strdup("inf");
	if ((*arg)->flags.plus)
		no_err &= add_plus_flag(pf, arg);
	if ((*arg)->flags.space)
	{
		if ((*arg)->flags.minus)
		{
			no_err &= add_space_flag(pf, arg);
			no_err &= set_field_width(pf, arg);
		}
		else
		{
			no_err &= set_field_width(pf, arg);
			no_err &= add_space_flag(pf, arg);
		}
	}
	else
		no_err &= set_field_width(pf, arg);
	if (!no_err)
		pf->err = 1;
	else
		(*arg)->out_len = ft_strlen((*arg)->out);
}

static void	minus_inf(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	(*arg)->out = ft_strdup("-inf");
	no_err &= (*arg)->out != NULL;
	no_err &= set_field_width(pf, arg);
	if (!no_err)
		pf->err = 1;
	else
		(*arg)->out_len = ft_strlen((*arg)->out);
}

int			nan_inf(t_printf *pf, t_arg **arg, long double db)
{
	(*arg)->flags.zero *= (db == 1 / 0.0 || db == 1 / -0.0 || db != db ? 0 : 1);
	if (db == 1 / 0.0)
		plus_inf(pf, arg);
	else if (db == 1 / -0.0)
		minus_inf(pf, arg);
	else if (db != db)
		nan(pf, arg);
	else
		return (0);
	if (!(*arg)->out)
		pf->err = 1;
	return (1);
}

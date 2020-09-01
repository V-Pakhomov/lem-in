/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:34:44 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:11 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

int		add_space_flag(t_printf *pf, t_arg **arg)
{
	char first_symb;
	char *tmp_out;

	first_symb = (*arg)->out[0];
	if (first_symb == '-' || first_symb == ' ')
		return (1);
	if (first_symb == '0' && (int)ft_strlen((*arg)->out) > (*arg)->precision)
		if ((*arg)->conversion != 'f' ||
			((*arg)->out[1] >= '0' && (*arg)->out[1] <= '9'))
		{
			(*arg)->out[0] = ' ';
			return (1);
		}
	tmp_out = ft_strjoin(" ", (*arg)->out);
	if (!tmp_out)
		return (error(pf));
	free((*arg)->out);
	(*arg)->out = tmp_out;
	return (1);
}

int		add_plus_flag(t_printf *pf, t_arg **arg)
{
	char *tmp;
	char *sign;

	if ((*arg)->out[0] == '-')
		return (1);
	sign = ft_strdup("+");
	if (!sign)
		return (error(pf));
	if (!(tmp = ft_strjoin(sign, (*arg)->out)))
	{
		free(sign);
		return (error(pf));
	}
	free(sign);
	free((*arg)->out);
	(*arg)->out = tmp;
	return (1);
}

void	check_flags(t_arg **arg)
{
	int i;

	(*arg)->flags.minus = 0;
	(*arg)->flags.plus = 0;
	(*arg)->flags.zero = 0;
	(*arg)->flags.number_sign = 0;
	(*arg)->flags.space = 0;
	i = 1;
	while ((*arg)->arg[i])
	{
		if ((*arg)->arg[i] == '.')
			skip_precicison_part(&i, (*arg)->arg);
		(*arg)->flags.minus |= ((*arg)->arg[i] == '-');
		(*arg)->flags.plus |= ((*arg)->arg[i] == '+');
		(*arg)->flags.zero |= ((*arg)->arg[i] == '0' &&
								!ft_isdigit((*arg)->arg[i - 1]));
		(*arg)->flags.number_sign |= ((*arg)->arg[i] == '#');
		(*arg)->flags.space |= ((*arg)->arg[i] == ' ');
		i++;
	}
	if ((*arg)->flags.minus || (ft_strchr((*arg)->arg, '.') &&
								(*arg)->is_num && (*arg)->conversion != 'f'))
		(*arg)->flags.zero = 0;
	if ((*arg)->flags.plus)
		(*arg)->flags.space = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:52:49 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:08 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	field_width_with_flag(t_printf *pf, t_arg **arg, int size, char c)
{
	char *width_part;
	char *tmp_out;

	if (!(width_part = (char *)malloc(size * sizeof(char))))
		return (error(pf));
	width_part = ft_memset(width_part, c, size - 1);
	width_part[size - 1] = '\0';
	if ((*arg)->flags.minus)
		tmp_out = ft_strjoin((*arg)->out, width_part);
	else
		tmp_out = ft_strjoin(width_part, (*arg)->out);
	if (!tmp_out)
	{
		free(width_part);
		return (error(pf));
	}
	free((*arg)->out);
	free(width_part);
	(*arg)->out = tmp_out;
	return (1);
}

int			set_field_width(t_printf *pf, t_arg **arg)
{
	int		width_size;
	int		tmp_precision;

	width_size = (*arg)->field_width - ft_strlen((*arg)->out) + 1;
	if (width_size <= 1)
		return (1);
	if (!(*arg)->flags.zero)
		return (field_width_with_flag(pf, arg, width_size, ' '));
	else if ((*arg)->is_num)
	{
		tmp_precision = (*arg)->precision;
		(*arg)->precision = (*arg)->field_width - ((*arg)->out[0] == '-' ||
													(*arg)->out[0] == '+');
		if (!set_precision(pf, arg))
			return (error(pf));
		(*arg)->precision = tmp_precision;
		return (1);
	}
	else
		return (field_width_with_flag(pf, arg, width_size, '0'));
}

void		get_field_width(t_arg **arg)
{
	int i;

	(*arg)->field_width = 0;
	i = 0;
	while ((*arg)->arg[i])
	{
		while ((*arg)->arg[i] &&
				((*arg)->arg[i] <= '0' || (*arg)->arg[i] > '9'))
		{
			if ((*arg)->arg[i] == '.')
				skip_precicison_part(&i, (*arg)->arg);
			else
				i++;
		}
		if ((*arg)->arg[i])
		{
			(*arg)->field_width = ft_atoi((*arg)->arg + i);
			skip_digits((*arg)->arg, &i);
		}
	}
	if ((*arg)->field_width > MAX_INT)
		(*arg)->field_width = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:37:13 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:13 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	is_allowed_symbol(char c)
{
	if (!c)
		return (0);
	if (ft_strchr("hlL#-+ .", c) == NULL && (c > '9' || c < '0'))
		return (0);
	return (1);
}

static int	get_part_len(char *format, int *i, int *len)
{
	int begin;

	begin = *i;
	if (format[begin] == '%')
	{
		(*i)++;
		while (is_allowed_symbol(format[*i]))
			(*i)++;
		if (!format[*i])
			return (0);
		(*i)++;
		*len = *i - begin;
	}
	else
	{
		while (format[*i] && format[*i] != '%')
			(*i)++;
		*len = *i - begin;
	}
	return (1);
}

int			parse_format(t_printf *pf, char *format)
{
	int		i;
	int		begin;
	int		len;
	char	*substr;

	i = 0;
	while (format[i])
	{
		begin = i;
		if (!get_part_len(format, &i, &len))
			break ;
		substr = ft_strsub(format, begin, len);
		push_back_arg(&(pf->args), new_arg(pf, substr));
		free(substr);
		if (pf->err)
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:55:06 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:33 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	set_precision_size(t_arg *arg, char **precision_part, int arg_len)
{
	int	size;

	size = arg->precision - arg_len + 1 +
							(arg->out[0] == '-' || arg->out[0] == '+');
	if (!(*precision_part = (char*)malloc(size * sizeof(char))))
		return (0);
	(*precision_part)[size - 1] = '\0';
	*precision_part = ft_memset(*precision_part, '0', size - 1);
	if (arg->out[0] == '-' || arg->out[0] == '+')
		(*precision_part[0] = arg->out[0]);
	return (1);
}

int			set_precision(t_printf *pf, t_arg **arg)
{
	int		len;
	char	*tmp;
	char	*precision_part;
	int		sign;

	tmp = (*arg)->out;
	sign = ((*arg)->is_num && (tmp[0] == '-' || tmp[0] == '+'));
	tmp += sign;
	len = ft_strlen(tmp);
	if ((*arg)->precision <= len)
		return (1);
	if (!set_precision_size(*arg, &precision_part, len))
		return (error(pf));
	(*arg)->out = ft_strjoin(precision_part, tmp);
	free(precision_part);
	tmp -= sign;
	if (!(*arg)->out)
	{
		free(tmp);
		return (error(pf));
	}
	free(tmp);
	return (1);
}

void		get_precision(t_arg **arg)
{
	if ((*arg)->conversion == 'f')
		(*arg)->precision = 6;
	else
		(*arg)->precision = 1;
	if (ft_strchr((*arg)->arg, '.') == NULL)
		return ;
	if (!ft_isdigit(ft_strrchr((*arg)->arg, '.')[1]))
	{
		(*arg)->precision = 0;
		return ;
	}
	(*arg)->precision = ft_atoi(ft_strrchr((*arg)->arg, '.') + 1);
	if ((*arg)->precision < 0 || (*arg)->precision > MAX_INT)
		(*arg)->precision = 0;
}

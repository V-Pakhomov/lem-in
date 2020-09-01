/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skips.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:19:11 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:38:04 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

void	skip_digits(char *str, int *i)
{
	while (str[*i] && ft_isdigit(str[*i]))
		(*i)++;
}

void	skip_precicison_part(int *i, char *arg)
{
	(*i)++;
	skip_digits(arg, i);
}

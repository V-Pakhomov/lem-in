/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:17:34 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:15 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

void	free_all(t_printf *pf)
{
	t_arg *tmp;

	free(pf->all_conversions);
	while (pf->args != NULL)
	{
		tmp = pf->args->next;
		free(pf->args->arg);
		free(pf->args->out);
		if (pf->args->is_num)
			free(pf->args->length_modifier);
		free(pf->args);
		pf->args = tmp;
	}
}

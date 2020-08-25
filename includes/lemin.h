/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:23:16 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 15:36:56 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

typedef struct s_lemin
{
	int ants_num;
	int rooms_num;
	char **rooms;
	int **adj_matrix;
	int *used;
}t_lemin;

#endif
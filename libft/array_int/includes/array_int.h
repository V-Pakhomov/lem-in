/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:53:12 by Nik               #+#    #+#             */
/*   Updated: 2020/09/01 08:56:31 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_INT_H
# define ARRAY_INT_H
# define ARR_LEN arr[0]

# include "../../includes/libft.h"

int		*arr_new(char *arr);
int		arr_len(int *arr);
int		arr_get(int *arr, int index);
void	arr_set(int *arr, int index, int nbr);
void	arr_del(int *arr, int index, ...);
void	arr_print(int *arr);
void	arr_add(int **arr, int index, int nbr);

int		check_arr_input(char *nbr);
void	arr_copy(int *new, int *arr);

#endif

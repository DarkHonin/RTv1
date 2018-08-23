/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:36:30 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 09:48:59 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILFT_H
# define UTILFT_H

#include <math_ft.h>

typedef struct s_array
{
	void	*items;
	t_len	len;
	t_len	size;	
}	t_array;

t_array	*create_array(t_len size);
void	free_array(t_array *ar);
int		array_push(t_array *ar, void *item);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:23:35 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 12:32:01 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_1_H
# define RTV_1_H

# define WINDOW_W 800
# define WINDOW_H 800

#include <libft.h>
#include <get_next_line.h>

typedef	double	t_node_v;

typedef	enum	e_shape
{
	POINT,
	LINE,
	RECT
} t_shape_e;

typedef struct	s_vect
{
	t_node_v	*nodes;
	size_t		values;
} t_vect;

typedef struct	s_space
{
	t_vect	*bounds;
} t_space;

typedef union u_shape
{
	
} t_shape;


/*
*	Point
*/

t_vect	*point_c(size_t len, const t_node_v *values);

/*
*	Space
*/

t_space	*space_c(t_vect *bounds);

#endif
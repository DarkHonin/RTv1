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

# define POINT_C(q) point_c(3, (t_node_v[3]){q, q, q})

#include <libft.h>
#include <get_next_line.h>
#include <math.h>

typedef	double	t_node_v;

typedef enum	e_direction
{
	TOP,
	BOTTOM,
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_direction;

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
} 				t_vect;


typedef	struct	s_shape
{
	t_vect				**points;
	size_t				point_count;
	size_t				index;
	t_vect				*origen;
	t_vect				*rotation;
	t_vect				*scale;
	t_shape_e			type;
	struct s_shape		*next[6];
}				t_shape;

typedef struct	s_space
{
	t_vect	*bounds;
	t_shape	**shapes;
	size_t	shape_count;
} 				t_space;

/*
*	Point
*/

t_vect		*point_c(size_t len, const t_node_v *values);

void 		point_p(t_vect *point);
t_node_v	point_d(t_vect *a, t_vect *b);

/*
*	Shape
*/

t_shape		*shape_c(t_shape_e type);
void		shape_p(t_shape *shape);
void		shape_a(t_shape *shape, t_vect *p);

/*
*	Space
*/

t_space		*space_c(t_vect *bounds);
void		*space_a(t_space *space, t_shape *shape);
void		space_p(t_space *space);

#endif
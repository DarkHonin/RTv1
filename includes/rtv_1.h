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

#include <libft.h>
#include <get_next_line.h>
#include <math.h>

# define WINDOW_W 800
# define WINDOW_H 800

# define POINT_C(q) point_c(3, (t_node_v[3]){q, q, q})
# define DEG(rad) (rad * 180) / M_PI
# define RAD(deg) (deg / M_PI) * 180

# define TOP	(unsigned char)0x01
# define BOTTOM	(unsigned char)~0x01
# define NORTH	(unsigned char)0x02
# define SOUTH	(unsigned char)~0x02
# define EAST	(unsigned char)0x03
# define WEST	(unsigned char)~0x03

# define OPOSED(dir) (unsigned char)(~dir)


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

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
* Utils
*/

unsigned char	hob (unsigned char byte);
unsigned char	rot(unsigned char a);

/*
*	Point
*/

t_vect			*point_c(size_t len, const t_node_v *values);

void			point_set(t_vect *v, size_t i, t_node_v val);

t_vect			*point_delta(t_vect *a, t_vect *b);
t_node_v		point_dis(t_vect *a, t_vect *b);
double 			*point_dir(t_vect *zero, t_vect *point);

void 			point_p(t_vect *point);
/*
*	Shape
*/

t_shape			*shape_c(t_shape_e type);

void			shape_a(t_shape *shape, t_vect *p);

void			shape_p(t_shape *shape);

/*
*	Space
*/

t_space			*space_c(t_vect *bounds);

void			*space_a(t_space *space, t_shape *shape);

void			space_p(t_space *space);

#endif
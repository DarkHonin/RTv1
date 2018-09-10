/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:34:16 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/31 11:54:32 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _3DFT_H
# define _3DFT_H

# include <libft.h>
# include <math_ft.h>
# include <math.h>
# include <utilft.h>
# define ROT_MATRIX_SIZE (t_size) {3, 3}
# define POINT_MATRIX_SIZE (t_size) {3, 1}
# define ORIGEN	(t_vect3) {1, 1, 1}
# define RAD(x)	(x / 180) * M_PI
enum	e_shape
{
	SHAPE_LINE,
	SHAPE_PLANE,
	SHAPE_SPHERE,
	SHAPE_CILINDER,
	SHAPE_BOX,
	SHAPE_LAMP,
	SHAPE_CAMERA
};

enum	e_shape_component
{
	SHAPE_C_POSITION,
	SHAPE_C_SIZE,
	SHAPE_C_ROTATION
};

typedef	enum e_shape			t_shape_type;
typedef	enum e_shape_component	t_shape_c;
typedef	struct			s_shape
{
	t_vect3				components[3];
	int					color[3];
	t_shape_type		type;
}						t_shape;
typedef	t_array			t_space;
typedef	struct			s_stage
{
	t_space		*space;
	t_shape		camera;
}						t_stage;

typedef void (*t_mtr_config)(t_value_m mtr, t_value angle);

void		stage_add_space(t_shape e);
t_stage		*get_stage();
const char	*shape_get_name(t_shape_type t);
void		shape_set(t_shape_c com, t_value_v data, t_shape *s);
t_value_v	shape_space_line(t_vect3 pos, t_shape line);
t_value_v	shape_space_to_global(t_value_v local, t_shape shape);
t_value_v	point_normilize(t_value_v point_3d);
t_value_m	matrix_global_rot(t_value x, t_value y, t_value z);
void		matrix_rotate_global(t_value_v point, t_value_v angles);
void		shape_space_rotate(t_value_v rot, t_value_v point);

#endif
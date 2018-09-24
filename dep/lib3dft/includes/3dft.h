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
# define SPACE_COMPONENT_SIZE (t_size) {4, 4}
# define ORIGEN	(t_vect3) {1, 1, 1}
# define RAD(x)	(x / 180) * M_PI
# define CAMERA get_stage()->camera;
enum	e_shape
{
	SHAPE_LINE,
	SHAPE_PLANE,
	SHAPE_SPHERE,
	SHAPE_RAY,
	SHAPE_CILINDER,
	SHAPE_BOX,
	SHAPE_LAMP,
	SHAPE_CAMERA
};

enum	e_space_component
{
	SPACE_C_X,
	SPACE_C_Y,
	SPACE_C_Z,
	SPACE_C_T
};

typedef	enum e_shape			t_shape_type;
typedef	enum e_space_component	t_space_c;

typedef	struct			s_space_empty
{
	t_value_m			components;
	t_value_m			inverse;
	t_value_v			x_component;
	t_value_v			y_component;
	t_value_v			z_component;
	t_value_v			translation;
	t_shape_type		type;
	void				*parent;
}						t_space_empty;

typedef	union			u_space
{
	t_space_empty;
}						t_space;

typedef	struct			s_stage
{
	t_space				*global_space;
	t_space				*camera_space;
}						t_stage;

typedef	void 	(*t_mtr_config)(t_value_m, t_value);
t_space			*create_space();
t_stage			*create_stage();
void			matrix_configure_x_axis(t_value_m mtr, t_value angle);
void			matrix_configure_y_axis(t_value_m mtr, t_value angle);
void			matrix_configure_z_axis(t_value_m mtr, t_value angle);
void			matrix_rotate_global(t_value_v point, t_value_v angles);
void			space_local(t_space s, t_value_v point);
void			space_parent(t_space s, t_value_v point);
void			space_global(t_space s, t_value_v point);
void			space_camera(t_space s, t_value_v point);
t_stage			*get_stage();
void			space_set(t_space *s, t_space_c comp, t_value_v val);
#endif
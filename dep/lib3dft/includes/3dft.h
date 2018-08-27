/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:34:16 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/27 12:32:33 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _3DFT_H
# define _3DFT_H

# include <libft.h>
# include <math_ft.h>
# include <utilft.h>
# define ROT_MATRIX_SIZE (t_size) {3, 3}
enum	e_shape
{
	LINE,
	PLANE_RECT,
	PLANE_CIRCLE,
	BODY_QUAD,
	BODY_VOX,
	BODY_CYLANDER,
	BODY_CIRCLE,
	CAMERA
};

typedef	enum e_shape	t_shape_type;
typedef	struct			s_shape
{
	t_vect3				anchor;
	t_vect3				size;
	t_vect3				rotation;
	t_shape_type		type;
}						t_shape;
typedef	t_array			t_space;
typedef	struct			s_stage
{
	t_space		*space;
	t_shape		camera;
}						t_stage;

void		log_shape(t_shape *e);
char		*get_shape_string(t_shape_type s);
t_stage		*get_stage();
void		set_projection_surface(t_shape *camera, t_value_v vals);
void		set_projection_rotation(t_shape *camera, t_value_v vals);
void		set_projection_anchor(t_shape *camera, t_value_v vals);
t_value		get_fov(t_shape cam);
t_value_v	get_point_projection(t_shape cam, t_value_v point, t_len el);
t_value_v	cam_dir_from_origen(t_shape cam);
t_value_m	matrix_x_rot(t_value angle);
t_value_m	matrix_y_rot(t_value angle);
t_value_m	matrix_z_rot(t_value angle);
t_value_m	matrix_global_rot(t_value x, t_value y, t_value za);
t_value_m	guide_anchor_to_points(t_shape sp);
#endif
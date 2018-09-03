#include <3dft.h>
#include <math.h>

t_value	get_fov(t_shape cam)
{
	t_value	ang;
	t_value x;
	t_value y;

	x = cam.size[2];
	y = cam.size[0];
	ang = atan2(y , x);
	if (ang <= 0)
            ang += 2 * M_PI;
	return (ang * (180 / M_PI));
}

t_value_v	cam_dir_from_origen(t_shape cam)
{
	t_value_v	ang;
	t_value 	x;
	t_value 	y;
	t_len 		i;

	ang = create_value_v(3);
	i = 0;
	while (i <= 3)
	{
		x = cam.anchor[i - ((i == 2) * 2)];
		y = cam.anchor[i + (1 * (i != 2))];
		ang[i] = atan2(y , x);
		if (ang[i] <= 0)
            ang[i] += 2 * M_PI;
		i++;
	}
	return (ang);
}

t_value_v	cam_triangulate(t_value_v prog, t_shape cam)
{
	t_value_v	delta;
	t_value		r;
	t_value_v	dir;
	t_value_v	pos;

	pos = create_value_v(2);
	delta = vect_diff(prog, cam.anchor, 3);
	dir = create_value_v(3);
	dir[2] = vect_direction(delta, 3, Z_AXIS);
	dir[1] = vect_direction(delta, 3, Y_AXIS);
	dir[0] = vect_direction(delta, 3, X_AXIS);

	pos[0] = (cos(dir[0]) * -cam.size[2]);
	pos[1] = (cos(dir[2]) * -cam.size[2]);
	return (pos);
}

t_value_v	get_point_projection(t_shape cam, t_value_v point, t_len el)
{
	t_value_v	ret;
	t_value_v	dir;
	t_value_m	rt;
	t_value_m	hold;
	t_value_v	dist;

	ret = create_value_v(2);
	dist = vect_diff(point, ORIGEN, 3);
	log_state(INFO, "DELTA", &get_point_projection);

	dir = cam_dir_from_origen(cam);
	log_state(INFO, "DIR", &get_point_projection);
	
	rt = matrix_global_rot(-dir[0], -dir[1], -dir[2]);
	log_state(INFO, "MATRIX", &get_point_projection);
	
	hold = matrix_multiply(&dist, rt, (t_size){el, 1}, ROT_MATRIX_SIZE);
	log_state(INFO, "TRANSLATION", &get_point_projection);
	
	ret = cam_triangulate(hold[0], cam);
	log_state(INFO, "TRIANGULATION", &get_point_projection);
	
	ret[0] = (cam.size[0] / 2) + ret[0];
	ret[1] = (cam.size[1] / 2) + ret[1];
	
	return(ret);
}


/*
**	The point is iether on the x-axis or the y axis
**	of the viewport.
**	The function computes the slope and the y intersect of the
**	ray in 3D space
*/

t_value_v	cam_spawn_ray(t_shape cam, t_value point, t_axis a)
{
	t_value_v ret;
	t_value_v proj;
	t_value_v size;

	ret = create_value_v(2);
	proj = project_view_axis(cam.anchor, a);
	size = project_view_axis(cam.size, a);
	ret[0] = (point - size[0]) / size[1];
	ret[1] = size[1] - (ret[0] * (size[0]));
	ret[1] += proj[1];
	return (ret);
}
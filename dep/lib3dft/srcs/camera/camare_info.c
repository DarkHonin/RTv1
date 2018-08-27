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
	t_len i;

	ang = create_value_v(3);
	i = 0;
	while (i <= 3)
	{
		x = cam.anchor[i - ((i == 2) * 2)];
		y = cam.anchor[i + (1 * (i != 2))];
		ang[i] = atan2(y , x);
		if (ang[i] <= 0)
            ang[i] += 2 * M_PI;
		ang[i] *= (180 / M_PI);
		i++;
	}
	return (ang);
}

t_value_v	get_point_projection(t_shape cam, t_value_v point, t_len el)
{
	t_value_v	ret;
	t_value_v	rot;
	t_value_m	rt;
	t_value_m	hold;
	t_value_v	norm;

	//log_open(INFO, "PROJECTION", &get_point_projection);
	ret = create_value_v(2);
	//log_state("CREATED RETURN", &get_point_projection);

	rot = cam_dir_from_origen(cam);
	//log_state("RETRIEVED DIRECTION", &get_point_projection);

	rt = matrix_global_rot(rot[0], rot[1], rot[2]);
	//log_state("RETRIEVED MATRIX", &get_point_projection);

	norm = vect_diff(point, cam.anchor, 3);
	//log_state("NORMALISED", &get_point_projection);

	hold = matrix_multiply(&norm, rt, (t_size){el, 1}, ROT_MATRIX_SIZE);
	//log_state("PROJECTED", &get_point_projection);
	
	ret[0] = hold[0][0] ;
	ret[1] = hold[0][2];
	ret[0] = (cam.size[0] / 2) - ret[0];
	ret[1] = (cam.size[1] / 2) - ret[1];
	//log_state("RASTERISED", &get_point_projection);
	return(ret);
}
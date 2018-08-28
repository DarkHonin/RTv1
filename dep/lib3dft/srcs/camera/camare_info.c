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
		i++;
	}
	return (ang);
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
	dir = cam_dir_from_origen(cam);

	rt = matrix_x_rot(dir[0]);

	hold = matrix_multiply(&dist, rt, (t_size){el, 1}, ROT_MATRIX_SIZE);
	
	ret[0] = hold[0][0];
	ret[1] = hold[0][2];
	ret[0] = (cam.size[0] / 2) - ret[0];
	ret[1] = (cam.size[1] / 2) - ret[1];
	return(ret);
}
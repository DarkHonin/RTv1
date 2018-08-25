/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camare_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:33:45 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/25 10:54:20 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>
#include <math.h>

t_value	get_fov(t_shape cam)
{
	t_value	ang;
	t_value x;
	t_value y;

	x = cam.values[1][2];
	y = cam.values[1][0];
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
		x = cam.values[0][i - ((i == 2) * 2)];
		y = cam.values[0][i + (1 * (i != 2))];
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
	t_value_m mtr;
	t_value_m tmtr;
	t_value_v ret;

	tmtr = matrix_x_rot(cam.values[2][0] * (M_PI / 180));
	mtr = matrix_y_rot(cam.values[2][1] * (M_PI / 180));
	mtr = matrix_multiply(tmtr, mtr, ROT_MATRIX_SIZE, ROT_MATRIX_SIZE);
	ret = *matrix_multiply(&point, mtr, (t_size){el, 1}, ROT_MATRIX_SIZE);

	return(ret);
}
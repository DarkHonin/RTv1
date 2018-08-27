/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matricies.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:34:44 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/27 13:25:24 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>
#include <math.h>

t_value_m	matrix_x_rot(t_value angle)
{
	static t_value_m	mtr = NULL;

	if (!mtr)
		mtr = create_value_m(ROT_MATRIX_SIZE);
	matrix_set_row(mtr, (t_vect){1, 0, 			0			}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){0, cos(angle), -sin(angle)	}, ROT_MATRIX_SIZE, 1);
	matrix_set_row(mtr, (t_vect){0, sin(angle), cos(angle)	}, ROT_MATRIX_SIZE, 2);
	return (mtr);
}

t_value_m	matrix_y_rot(t_value angle)
{
	static t_value_m	mtr = NULL;

	if (!mtr)
		mtr = create_value_m(ROT_MATRIX_SIZE);
	matrix_set_row(mtr, (t_vect){cos(angle),	0, sin(angle)	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){0, 			1,			0	}, ROT_MATRIX_SIZE, 1);
	matrix_set_row(mtr, (t_vect){-sin(angle), 	0, cos(angle)	}, ROT_MATRIX_SIZE, 2);
	return (mtr);
}

t_value_m	matrix_z_rot(t_value angle)
{
	static t_value_m	mtr = NULL;

	if (!mtr)
		mtr = create_value_m(ROT_MATRIX_SIZE);
	matrix_set_row(mtr, (t_vect){ cos(angle), -sin(angle),	0	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){ sin(angle), cos(angle),	0	}, ROT_MATRIX_SIZE, 1);
	matrix_set_row(mtr, (t_vect){ 0, 			0		,	1	}, ROT_MATRIX_SIZE, 2);
	return (mtr);
}

t_value_m	matrix_global_rot(t_value x, t_value y, t_value z)
{
	t_value_m _x;
	t_value_m _y;
	t_value_m _z;
	t_value_m hold;
	t_value_m ret;
	
	_x = matrix_x_rot(x);
	_y = matrix_x_rot(y);
	_z = matrix_x_rot(z);
	hold = matrix_multiply(_x, _y, ROT_MATRIX_SIZE, ROT_MATRIX_SIZE);
	ret = matrix_multiply(hold, _z, ROT_MATRIX_SIZE, ROT_MATRIX_SIZE);
	free_value_m(hold, ROT_MATRIX_SIZE[1]);
	return (ret);
}
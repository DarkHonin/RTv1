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

void		matrix_configure_x_axis(t_value_m mtr, t_value angle)
{
	matrix_set_row(mtr, (t_vect){1, 0, 			0			}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){0, cos(angle), -sin(angle)	}, ROT_MATRIX_SIZE, 1);
	matrix_set_row(mtr, (t_vect){0, sin(angle), cos(angle)	}, ROT_MATRIX_SIZE, 2);
}

void		matrix_configure_y_axis(t_value_m mtr, t_value angle)
{
	matrix_set_row(mtr, (t_vect){cos(angle),	0, sin(angle)	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){0, 			1,			0	}, ROT_MATRIX_SIZE, 1);
	matrix_set_row(mtr, (t_vect){-sin(angle), 	0, cos(angle)	}, ROT_MATRIX_SIZE, 2);
}
void		matrix_configure_z_axis(t_value_m mtr, t_value angle)
{
	matrix_set_row(mtr, (t_vect){ cos(angle), -sin(angle),	0	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){ sin(angle), cos(angle),	0	}, ROT_MATRIX_SIZE, 1);
	matrix_set_row(mtr, (t_vect){ 0, 			0		,	1	}, ROT_MATRIX_SIZE, 2);
}

const t_mtr_config	matrix_config_provider(t_axis ax)
{
	const	t_mtr_config	f[4] = {
		&matrix_configure_x_axis,
		&matrix_configure_y_axis,
		&matrix_configure_z_axis
	};
	return (f[ax]);
}

t_value_v	matrix_rotate(t_value_v	point, t_axis a, t_value ang)
{
	t_value_m		mtr;
	t_mtr_config	f;
	t_value_m		hold;
	t_value_v		ret;

	mtr = create_value_m(ROT_MATRIX_SIZE);
	f = matrix_config_provider(a);
	f(mtr, ang);
	hold = matrix_multiply(&point, mtr, POINT_MATRIX_SIZE, ROT_MATRIX_SIZE);
	ret = hold[0];
	free(hold);
	return (ret);
}

void		matrix_rotate_global(t_value_v point, t_value_v angles)
{
	t_len		i;
	t_value_v	hold_a;
	t_value_v	hold_b;

	i = 0;
	hold_a = clone_value_v(point, 3);
	while (i < 3)
	{
		hold_b = matrix_rotate(hold_a, i, angles[i]);
		vect_swap(&hold_a, hold_b);
		i++;
	}
	vect_set(point, hold_a, 3);
	free(hold_a);
}
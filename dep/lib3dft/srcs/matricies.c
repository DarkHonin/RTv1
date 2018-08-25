/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matricies.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:34:44 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/25 10:44:55 by wgourley         ###   ########.fr       */
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
	matrix_set_row(mtr, (t_vect){0, cos(angle), -sin(angle)	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){0, sin(angle), cos(angle)	}, ROT_MATRIX_SIZE, 0);
	return (mtr);
}

t_value_m	matrix_y_rot(t_value angle)
{
	static t_value_m	mtr = NULL;

	if (!mtr)
		mtr = create_value_m(ROT_MATRIX_SIZE);
	matrix_set_row(mtr, (t_vect){cos(angle),	0, sin(angle)	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){0, 			1,			0	}, ROT_MATRIX_SIZE, 0);
	matrix_set_row(mtr, (t_vect){-sin(angle), 	0, cos(angle)	}, ROT_MATRIX_SIZE, 0);
	return (mtr);
}
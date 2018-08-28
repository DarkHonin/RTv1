/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matricies.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:32:35 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/28 13:32:35 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>

void	test_matrix_multiple()
{
	t_vect3		point			= {1, 4, 5};
	t_value_m	matrix_src;
	t_value_m	matrix_m_with;
	t_value_m	result;
	t_size		matrix_src_s	= {3, 3};
	t_size		point_size		= {3, 1};

	matrix_src = create_value_m(matrix_src_s);
	matrix_set_row(matrix_src, (t_vect3)	{4,		16, 	32}, matrix_src_s, 0);
	matrix_set_row(matrix_src, (t_vect3)	{7, 	65, 	12}, matrix_src_s, 1);
	matrix_set_row(matrix_src, (t_vect3)	{77, 	10,		45}, matrix_src_s, 2);

	matrix_m_with = create_value_m(matrix_src_s);
	matrix_set_row(matrix_m_with, (t_vect3)	{1,		0, 	0}, matrix_src_s, 0);
	matrix_set_row(matrix_m_with, (t_vect3)	{0, 	1, 	0}, matrix_src_s, 1);
	matrix_set_row(matrix_m_with, (t_vect3)	{0, 	0 ,	1}, matrix_src_s, 2);

	result = matrix_multiply(matrix_src, matrix_m_with, matrix_src_s, matrix_src_s);
	log_value_m(result, matrix_src_s);

	t_value_v q = ((t_value *)point);
	result = matrix_multiply(&q, matrix_m_with, point_size, matrix_src_s);
	log_value_m(result, MATRIX_RESULT_SIZE(point_size, matrix_src_s));
}
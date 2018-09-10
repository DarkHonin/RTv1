/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:16:58 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/03 22:16:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_value_v	point_normilize(t_value_v point_3d)
{
	t_vect2		proj;
	t_value_v	ret;
	t_shape		cam;

	proj[0] = point_3d[0] / -point_3d[2];
	proj[1] = point_3d[1] / -point_3d[2];
	ret = create_value_v(2);
	ret[0] = (1 + proj[0]) / 2;
	ret[1] = (1 + proj[1]) / 2;
	cam = get_stage()->camera;
	ret[0] *= cam.components[1][0];
	ret[1] *= cam.components[1][1];
	return (ret);
}
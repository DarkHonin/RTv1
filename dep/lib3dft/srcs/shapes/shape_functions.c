/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:34:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/30 22:34:24 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_value	shape_plane_intersect(t_shape s, t_value ray_slope,
			t_value ray_intersect, t_axis axis)
{
	t_value_v	ret;
	t_value		slope;
	t_value		intersect;

	slope = (s.anchor[1] - s.size[1]) / (s.anchor[2] - s.size[2]);
	intersect = s.anchor[1] - (slope * s.anchor[2]);
	if (slope / ray_slope == 1)
		return (0);
	ret = create_value_v(2);
	ret[0] = (ray_slope - slope) * (ray_intersect - intersect);
	ret[1] = (slope * ret[0]) + intersect;
	return (1);
}
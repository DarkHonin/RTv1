/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_geometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:21:35 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/31 11:41:33 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_value_v	plane_get_line(t_shape s, t_axis ax)
{
	return (line_get_info(s.anchor, s.size, ax));
}

t_value_v	line_get_info(t_value_v a, t_value_v offset, t_axis ax)
{
	t_value_v	or;
	t_value_v	cnt;
	t_value_v	ret;

	or = create_value_v(2);
	or[0] = a[ax];
	or[1] = a[(ax + 1) % 3];
	cnt = clone_value_v(or, 2);
	cnt[0] += (offset[ax] / 2);
	cnt[1] += (offset[(ax + 1) % 3] / 2);
	ret = create_value_v(2);
	ret[0] = offset[(ax + 1) % 3] / offset[ax];
	ret[1] = or[1] - (ret[0] * or[0]);
	free(or);
	free(cnt);
	return (ret);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:34:06 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/31 11:13:42 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

char	*get_shape_string(t_shape_type s)
{
	static char *names[] = {
		"PLANE_RECT",
		"PLANE_CIRCLE",
		"BODY_QUAD",
		"BODY_VOX",
		"BODY_CYLANDER",
		"BODY_CIRCLE",
		"CAMERA"
	};
	return (names[s]);
}

void	log_shape(t_shape *e)
{
	log_open(LOG, "LOG", &log_shape);
	ft_putstr(get_shape_string(e->type));
	log_close("log_shape");
	log_value_v(e->anchor, 3);
	log_value_v(e->size, 3);
	log_value_v(e->rotation, 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:34:06 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 12:18:11 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

char	*get_shape_string(t_shape_type s)
{
	static char *names[] = {
		"LINE",
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
	int y;
	int x;

	y = 0;
	log_open(LOG, "LOG", &log_shape);
	ft_putstr(get_shape_string(e->type));
	log_close("log_shape");
	while (y < 3)
	{
		log_open(LOG, "LOG", &log_shape);
		ft_putstr("[");
		ft_putnbr(y);
		ft_putstr("]");
		x = 0;
		while (x < 3)
		{
			ft_putchar('\t');
			ft_putnbr(e->values[y][x]);
			x++;
		}
		y++;
		log_close("log_shape");
	}
}
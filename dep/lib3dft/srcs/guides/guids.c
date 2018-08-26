/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:33:49 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/26 12:06:50 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sdlgf.h>

t_value_m	guide_anchor_to_points(t_shape sp)
{
	t_value_m	anchors;
	t_len x;

	anchors = create_value_m((t_size){3, 3});
	x = 0;
	while (x < 3)
	{
		matrix_set_row(anchors, sp.anchor, (t_size){3, 3}, x);
		anchors[x][x]+=20;
		x++;
	}
	return (anchors);
}
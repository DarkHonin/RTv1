/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_provider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:43:33 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/30 22:43:33 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_value		(*shape_get_function(t_shape_type e))(t_shape, t_value, t_value, t_axis)
{
	static t_shape_collider f[] = {
		&shape_plane_intersect
	};
	return (f[e]);
}
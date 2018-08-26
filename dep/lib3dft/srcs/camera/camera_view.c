/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:32:55 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/26 11:24:16 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

/*
**	projection requires 3 values;
**		0:	Width of viewport
**		1:	Height of viewport
**		2:	Depth of viewport
*/

static	t_value	set_pro(t_value a, t_value b, t_len i)
{
	log_open(LOG, "VIEW_CHANGE", &set_pro);
	ft_putstr("Index: ");
	ft_putnbr(i);
	ft_putstr("\tOriginal: ");
	ft_putnbr(a);
	ft_putstr("\tNew: ");
	ft_putnbr(b);
	log_close("set_pro");
	return (b);
}

void	set_projection_anchor(t_shape *camera, t_value_v vals)
{
	if(camera->type != CAMERA)
		warning_error("Invalid shape for camera projection");
	sync_function(camera->anchor, vals, &set_pro, 3);
}

void	set_projection_rotation(t_shape *camera, t_value_v vals)
{
	if(camera->type != CAMERA)
		warning_error("Invalid shape for camera projection");
	sync_function(camera->rotation, vals, &set_pro, 3);
}

void	set_projection_surface(t_shape *camera, t_value_v vals)
{
	if(camera->type != CAMERA)
		warning_error("Invalid shape for camera projection");
	sync_function(camera->size, vals, &set_pro, 3);
}
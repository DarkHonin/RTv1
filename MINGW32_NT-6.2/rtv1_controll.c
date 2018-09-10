/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:41:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/30 16:41:37 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>

void	trace_axis(t_axis e);

int key_event(int keycode, void *stage)
{
	t_stage *s = stage;
	for(t_len i = 0; i < s->space->len; i++)
	{
		((t_shape *)s->space->items)[i].components[SHAPE_C_ROTATION][2]+= 0.01;
		((t_shape *)s->space->items)[i].components[SHAPE_C_ROTATION][1]+= 0.01;
		((t_shape *)s->space->items)[i].components[SHAPE_C_ROTATION][0]+= 0.01;
	}
	stage_project_ortho();
	return (1);
}
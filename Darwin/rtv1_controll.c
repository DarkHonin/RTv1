/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:41:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/31 11:05:34 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>

int key_event(int keycode, void *stage)
{
	t_stage *e;

	e = stage;
	if (keycode == KEY_ESC)
		close_window();
	if (keycode == KEY_UP)
		((t_stage *)e)->camera.anchor[2]++;
	if (keycode == KEY_DOWN)
		((t_stage *)e)->camera.anchor[2]--;
	if (keycode == KEY_RIGHT)
		((t_stage *)e)->camera.anchor[0]--;
	if (keycode == KEY_LEFT)
		((t_stage *)e)->camera.anchor[0]++;
	if (keycode == KEY_W)
		((t_stage *)e)->camera.anchor[1]++;
	if (keycode == KEY_S)
		((t_stage *)e)->camera.anchor[1]--;
	return (1);
}
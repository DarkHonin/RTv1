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

int key_event(int keycode, void *stage)
{
	t_stage *e;

	e = stage;
	if (keycode == SDLK_ESCAPE)
		close_window();
	if (keycode == SDLK_UP)
		((t_stage *)e)->camera.anchor[2]++;
	if (keycode == SDLK_DOWN)
		((t_stage *)e)->camera.anchor[2]--;
	if (keycode == SDLK_RIGHT)
		((t_stage *)e)->camera.anchor[0]--;
	if (keycode == SDLK_LEFT)
		((t_stage *)e)->camera.anchor[0]++;
	if (keycode == SDLK_w)
		((t_stage *)e)->camera.anchor[1]++;
	if (keycode == SDLK_s)
		((t_stage *)e)->camera.anchor[1]--;
	return (1);
}
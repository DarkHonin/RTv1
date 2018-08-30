/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:34:42 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/30 12:59:12 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <3dft.h>
#include <stdio.h>
#include <math.h>
#include <sdlgf.h>

int	loop(t_stage *s)
{
	t_shape	c;
	t_len i;

	c.anchor[0] = 0;
	c.anchor[1] = 0;
	c.anchor[2] = 0;
	clean();
	trace_space(*s);	
	draw_shape_anchor(c, s->camera);
	flip();
	return (s!=NULL);
}

int event_handle(void *e)
{
	return 1;
}

int key_event(int keycode, void *stage)
{
	t_stage *e;

	e = stage;
	if (keycode == KEY_ESC)
		close_window();
	if (keycode == KEY_UP)
		((t_shape *)e->space->items)[0].anchor[2]++;
	if (keycode == KEY_DOWN)
		((t_shape *)e->space->items)[0].anchor[2]--;
	if (keycode == KEY_LEFT)
		((t_shape *)e->space->items)[0].anchor[0]--;
	if (keycode == KEY_RIGHT)
		((t_shape *)e->space->items)[0].anchor[0]++;
	if (keycode == KEY_W)
		((t_shape *)e->space->items)[0].anchor[1]++;
	if (keycode == KEY_S)
		((t_shape *)e->space->items)[0].anchor[1]--;
	return (1);
}

int main(int ac, char **av)
{
	t_stage		*stage;
	t_shape		hold;
	t_window	*win;

	stage = get_stage();
	set_projection_surface(&(stage->camera), (t_value[3]){F(WINDOW_W), F(WINDOW_H), F(50)});
	set_projection_anchor(&(stage->camera), (t_value[3]){F(20), F(20), F(20)});
	log_shape(&(stage->camera));
	win = get_window();

	hold.anchor[0] = 5;
	hold.anchor[1] = 5;
	hold.anchor[2] = 5;
	hold.size[0] = 5;
	hold.size[1] = 5;
	hold.size[2] = 5;
	hold.type = PLANE_RECT;
	array_push(stage->space, &hold);
	
	start_loop(&loop, stage);
}
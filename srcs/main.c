/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:34:42 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/31 11:16:36 by wgourley         ###   ########.fr       */
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
	//clean();
	//trace_space(*s);
	
	return (s!=NULL);
}

int event_handle(void *e)
{
	return 1;
}

int main(int ac, char **av)
{
	t_stage		*stage;
	t_shape		hold;
	t_window	*win;

	stage = get_stage();
	set_projection_surface(&(stage->camera), (t_value[3]){F(WINDOW_W), F(WINDOW_H), F(200)});
	set_projection_anchor(&(stage->camera), (t_value[3]){F(0), F(200), F(200)});
	log_value_v(project_view_axis(stage->camera.size, X_AXIS), 2);
	log_value_v(project_view_axis(stage->camera.size, Y_AXIS), 2);
	log_value_v(project_view_axis(stage->camera.size, Z_AXIS), 2);
	win = get_window();
	log_state(LOG, "--------------------------------------------", main);
	log_value_v(project_view_axis(stage->camera.size, X_AXIS), 2);
	log_value_v(cam_spawn_ray(stage->camera, 0, X_AXIS), 2);
	log_value_v(cam_spawn_ray(stage->camera, 200, X_AXIS), 2);
	log_state(LOG, "--------------------------------------------", main);
	log_value_v(project_view_axis(stage->camera.size, Y_AXIS), 2);
	log_value_v(cam_spawn_ray(stage->camera, 0, Y_AXIS), 2);
	log_value_v(cam_spawn_ray(stage->camera, 800, Y_AXIS), 2);
	log_state(LOG, "--------------------------------------------", main);
	log_value_v(project_view_axis(stage->camera.size, Z_AXIS), 2);
	log_value_v(cam_spawn_ray(stage->camera, 0, Z_AXIS), 2);
	log_value_v(cam_spawn_ray(stage->camera, 200, Z_AXIS), 2);
	//start_loop(&loop, stage);
}
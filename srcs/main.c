/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:34:42 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 13:32:25 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <3dft.h>
#include <stdio.h>

int	loop(t_stage *s)
{
	t_value_v	point;
	point = get_point_projection(s->camera, (t_value[3]){F(0), F(0), F(0)}, 3);
	put_pixel(point[0], point[1], (t_color) {255, 255, 255});
	flip();
	return (s!=NULL);
}

int event_hook()
{
	get_stage()->camera.values[2][0]++;
	return 1;
}

int main(void)
{
	t_stage		*stage;
	t_window	*win;

	stage = get_stage();
	set_projection_surface(&(stage->camera), (t_value[3]){F(WINDOW_W), F(WINDOW_H), F(0)});
	set_projection_anchor(&(stage->camera), (t_value[3]){F(10), F(10), F(10)});
	set_projection_rotation(&(stage->camera), cam_dir_from_origen(stage->camera));
	set_projection_anchor(&(stage->camera), (t_value[3]){F(10), F(10), F(-10)});
	log_shape(&(stage->camera));
	win = get_window();
	mlx_key_hook(win->window_pointer, &event_hook, NULL);
	start_loop(&loop, stage);
}
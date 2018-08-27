/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:34:42 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/27 14:51:21 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <3dft.h>
#include <stdio.h>
#include <math.h>
#include <sdlgf.h>
int	loop(t_stage *s)
{
	t_shape	q;
	q.anchor[0] = 0;
	q.anchor[1] = 0;
	q.anchor[2] = 0;
	clean();
	draw_shape_anchor(q, get_stage()->camera);
	flip();
	put_string(ft_itoa(get_stage()->camera.anchor[0]), 0, 0, (t_color){255, 255, 255});
	put_string(ft_itoa(get_stage()->camera.anchor[1]), 0, 15, (t_color){255, 255, 255});
	put_string(ft_itoa(get_stage()->camera.anchor[2]), 0, 30, (t_color){255, 255, 255});
	return (s!=NULL);
}

int event_hook()
{
	get_stage()->camera.anchor[2]++;
	return 1;
}

int main(void)
{
	t_stage		*stage;
	t_window	*win;

	stage = get_stage();
	set_projection_surface(&(stage->camera), (t_value[3]){F(WINDOW_W), F(WINDOW_H), F(0)});
	set_projection_anchor(&(stage->camera), (t_value[3]){F(20), F(20), F(20)});
	
	log_shape(&(stage->camera));
	win = get_window();
	mlx_key_hook(win->window_pointer, &event_hook, NULL);
	start_loop(&loop, stage);
}
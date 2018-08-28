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

void	test_matrix_multiple();

int	loop(t_stage *s)
{
	
	t_shape	q;
	t_shape	c;

	c.anchor[0] = ORIGEN[0];
	c.anchor[1] = ORIGEN[1];
	c.anchor[2] = ORIGEN[2];
	q.anchor[0] = 10;
	q.anchor[1] = 5;
	q.anchor[2] = 10;
	clean();
	draw_shape_anchor(q, s->camera);
	draw_shape_anchor(c, s->camera);
	SDL_SetWindowTitle(get_window()->window_pointer, ft_itoa(s->camera.anchor[0]));
	flip();
	return (s!=NULL);
}

int event_handle(void *e)
{
	SDL_Event *event;

	event = e;
	if (event->type == SDL_KEYUP)
	{
		if (event->key.keysym.sym == SDLK_LEFT)
			get_stage()->camera.anchor[0]--;
		else if (event->key.keysym.sym == SDLK_RIGHT)
			get_stage()->camera.anchor[0]++;
		if (event->key.keysym.sym == SDLK_DOWN)
			get_stage()->camera.anchor[1]--;
		else if (event->key.keysym.sym == SDLK_UP)
			get_stage()->camera.anchor[1]++;
		if (event->key.keysym.sym == SDLK_w)
			get_stage()->camera.anchor[2]--;
		else if (event->key.keysym.sym == SDLK_s)
			get_stage()->camera.anchor[2]++;

		
		t_value_v dir = cam_dir_from_origen(get_stage()->camera);
		log_value_v(dir, 3);
		t_value_m mtr = matrix_global_rot(dir[0], dir[1], dir[2]);
		log_value_m(mtr, ROT_MATRIX_SIZE);
	}
	return 1;
}

int main(int ac, char **av)
{
	test_matrix_multiple();

	t_stage		*stage;
	t_window	*win;

	stage = get_stage();
	set_projection_surface(&(stage->camera), (t_value[3]){F(WINDOW_W), F(WINDOW_H), F(0)});
	set_projection_anchor(&(stage->camera), (t_value[3]){F(20), F(20), F(20)});
	log_shape(&(stage->camera));
	win = get_window();
	//mlx_key_hook(win->window_pointer, &event_hook, NULL);
	start_loop(&loop, stage);

}
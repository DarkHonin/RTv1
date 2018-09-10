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
	read_shapes("stage");
	shape_set(SHAPE_C_SIZE, (t_vect3){WINDOW_W, WINDOW_H, 1}, &(stage->camera));
	stage_project_ortho();
	start_loop(&loop, stage);
}
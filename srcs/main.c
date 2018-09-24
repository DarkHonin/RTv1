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

int	loop(void *arg)
{
	return (1);
}

int main(int ac, char **av)
{
	t_stage	*stage;
	t_vect4	point = {20, 50, 5, 1};
	t_vect2 cp;
	stage = get_stage();
	space_set(stage->camera_space, SPACE_C_T, (t_vect){10, 10, 10, 1});
	log_value_v(point, 4);
	space_global(*(stage->global_space), point);
	log_value_v(point, 4);
	vect_set(point, (t_vect4) {20, 50, 5, 1}, 4);
	space_camera(*(stage->global_space), point);
	log_value_v(point, 4);
	cp[0] = point[0] / (-point[2]);
	cp[1] = point[1] / (-point[2]);
	log_value_v(cp, 2);
}
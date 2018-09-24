/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:00:02 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/17 10:00:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

void	space_local(t_space s, t_value_v point)
{
	t_value_m	hold;

	hold = matrix_multiply(&point, s.components, (t_size){4, 1}, SPACE_COMPONENT_SIZE);
	log_value_m(hold, (t_size){4, 1});
	vect_set(point, *hold, 4);
	free_value_m(hold, 1);
}

void	space_parent(t_space s, t_value_v point)
{
	space_local(s, point);
	if (s.parent != NULL)
		space_local(*((t_space *)s.parent), point);
}

void	space_global(t_space s, t_value_v point)
{
	space_local(s, point);
	if (s.parent != NULL)
		space_global(*((t_space *)s.parent), point);
}

void	space_camera(t_space s, t_value_v point)
{
	t_stage *stage;
	t_value_m hold;
	t_value_m bold;

	space_global(s, point);
	stage = get_stage();
	hold = matrix_multiply(&point, stage->camera_space->inverse, (t_size){4, 1}, SPACE_COMPONENT_SIZE);
	vect_set(point, *hold, 4);
	free_value_m(hold, 1);
}
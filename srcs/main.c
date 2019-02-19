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
#include <stdio.h>
#include <math.h>


int	loop(void *arg)
{
	return (1);
}

int main(int ac, char **av)
{
	t_space *sp = space_c(POINT_C(100));
	t_shape *sh = shape_c(POINT);
	t_shape *sh1 = shape_c(POINT);
	t_shape *sh2 = shape_c(POINT);

	sh1->origen = POINT_C(1);
	sh2->origen = point_c(3, (t_node_v[3]){1, 0, 0.5});
	
	space_a(sp, sh);
	space_a(sp, sh1);
	space_a(sp, sh2);
}
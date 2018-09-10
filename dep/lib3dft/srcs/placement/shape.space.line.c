/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.space.line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:37:36 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/04 20:37:36 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>
#include <math.h>

/*
**	shape space functions in the following way.
**
**	pos		=	[	x,			y,			z]
**	  e.g.		[	0.4,		0.5,		0]
**	size	=	[	X			Y			Z]
**				----|-----------|-----------|-
**			  		v		 	v			v
**				X * 0.4	  	Y * 0.5 	  Z * 0
*/

t_value_v	shape_space_line(t_vect3 pos, t_shape line)
{
	t_value_v	disp;
	t_value_v	grep;
	t_value_v	plep;

	disp = vect_multiply(pos, line.components[SHAPE_C_SIZE], 3);
	grep = vect_devide(line.components[SHAPE_C_SIZE], (t_vect3){2, 2, 2}, 3);
	plep = vect_diff(disp, grep, 3);
	shape_space_rotate(line.components[SHAPE_C_ROTATION], plep);
	
	free(disp);
	free(grep);
	return (plep);
}

/*
**	Rotation works in the same way as getting the line space,
**	only in this case you define the amount of radians.
**
**	rot		=	[	x,			y,			z	]
**	  e.g.		[	0.4,		0.5,		0	]
**				----|-----------|-----------|----
**					V			V			V
**		(2 * 0.4) * pi	  (2 * 0.5) * pi   (2 * 0) * pi
*/

void	shape_space_rotate(t_value_v rot, t_value_v point)
{
	t_value_v	hold;
	t_value_v	rrt;

	hold	=	vect_multiply(rot, (t_vect3){2, 2, 2}, 3);
	rrt		=	vect_multiply(hold, (t_vect3){M_PI, M_PI, M_PI}, 3);
	matrix_rotate_global(point, rrt);
}
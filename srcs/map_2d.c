/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 09:04:00 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/01 09:04:00 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <math.h>

/*
	the axis being traced will be the one perpindicular to the line of sight
*/

t_value_v	project_view_axis(t_value_v s, t_axis a);

void	draw_axis()
{
	t_size	px;
	px[1] = 0;
	while (px[1] < WINDOW_H)
	{
		px[0] = 0;
		while (px[0] < WINDOW_W)
		{
			if ((px[0] == (WINDOW_C_W) && px[1] % 50 < 10) || (px[1] == (WINDOW_C_H) && px[0] % 50 < 10))
				put_pixel(px[0], px[1], (t_color){100, 100, 100});
			px[0]++;
		}
		px[1]++;
	}
}

void draw_shapes(t_space s, t_axis a)
{
	t_len	sh;
	t_value_v axo;
	t_value_v l;
	t_value_v c;
	t_shape *shapes;

	sh = 0;
	shapes = s.items;
	while (sh < s.len)
	{
		axo = project_view_axis(shapes[sh].anchor, a);
		axo[0] += WINDOW_C_W;
		axo[1] += WINDOW_C_H;
		c = clone_value_v(axo, 2);
		l = project_view_axis(shapes[sh].size, a);
		axo[0] -= (l[0] / 2);
		axo[1] -= (l[1] / 2);
		l[0] = l[0] + axo[0];
		l[1] = l[1] + axo[1];
		draw_line(axo, l ,2, (t_color){255, 0, 0});
		put_pixel(c[0], c[1], (t_color){255, 255, 255});
		free(axo);
		free(l);
		sh++;
	}
}

void	trace_shapes(t_value_v ray, t_axis a)
{
	t_len	sh;
	t_value_v axo;
	t_value_v l;
	t_vect2 shl;
	t_vect2	col;
	t_shape *shapes;

	shapes = get_stage()->space->items;
	sh = 0;
	while (sh < get_stage()->space->len)
	{
		axo = project_view_axis(shapes[sh].anchor, a);
		l = project_view_axis(shapes[sh].size, a);
		l[0] /= 2;
		l[1] /= 2;
		shl[0] = l[1] / l[0];
		shl[1] = axo[1] - (axo[0] * shl[0]);
		col[0] = (shl[0] - ray[0]) * (shl[1] - ray[1]);
		col[1] = (shl[0] * col[0]) + shl[1];
		if (col[0] - axo[0] < l[0] && col[0] - axo[0] > - l[0])
			put_pixel(col[0] + WINDOW_C_W, col[1] + WINDOW_C_H, shapes[sh].color);
		free(axo);
		free(l);
		sh++;
	}
}

void	trace_rays(t_axis e)
{
	t_shape 	cam;
	t_value_v	pos;
	t_value		v;
	t_vect2		ray;
	t_value		x;

	cam = get_stage()->camera;
	pos = project_view_axis(cam.anchor, e);
	v = 0;
	while (v < WINDOW_H)
	{
		ray[0] = (v - WINDOW_C_H) /  pos[0];
		ray[1] = pos[1] - (ray[0] * pos[0]);
		put_pixel(WINDOW_C_W, ray[1], (t_color){155, 155, 0});
		x = (-ray[1]) / ray[0];
		put_pixel(x, WINDOW_C_H, (t_color){155, 155, 0});
		v++;
	}
}

void	draw_L(t_value m, t_value d, t_color c)
{
	t_value x;
	t_value y;

	x = 0;
	while (x <= WINDOW_W)
	{
		y = (m * (x - WINDOW_C_W)) + d;
		put_pixel(x, y + WINDOW_C_H, c);
		x++;
	}
}

void	trace_axis(t_axis e)
{
	t_value_v	axo;
	t_vect3		l = {10, 10};
	t_space		sp;
	t_value_v	a;
	t_vect2		rt;
	t_value_v	b;

	sp = *get_stage()->space;

	draw_axis();
	
	axo = project_view_axis(get_stage()->camera.anchor, e);
	rt[0] = axo[1]/axo[0];
	rt[1] = axo[1] - (axo[0] * rt[0]);
	if (e == X_AXIS)
		draw_L(rt[0], rt[1], (t_color){255, 0, 0});
	if (e == Y_AXIS)
		draw_L(rt[0], rt[1], (t_color){0, 255, 0});
	if (e == Z_AXIS)
		draw_L(rt[0], rt[1], (t_color){0, 0, 255});
	put_pixel(axo[0] + WINDOW_C_W, axo[1] + WINDOW_C_H, (t_color){255,0,255});
	
	free(axo);
}

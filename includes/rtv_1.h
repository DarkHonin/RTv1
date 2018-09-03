/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:23:35 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 12:32:01 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_1_H
# define RTV_1_H

# define WINDOW_W 800
# define WINDOW_H 600

#include <libft.h>
#include <math_ft.h>
#include <get_next_line.h>
#include <utilft.h>
#include <sdlgf.h>

#define F(i) (t_value) i
void	trace_x_axis();
void	trace_y_axis();
void	trace_z_axis();

#endif
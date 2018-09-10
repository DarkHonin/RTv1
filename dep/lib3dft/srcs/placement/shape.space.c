/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:23:43 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/04 20:23:43 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_value_v	shape_space_to_global(t_value_v local, t_shape shape)
{
	t_value_v	ret;

	ret = vect_sum(local, shape.components[SHAPE_C_POSITION], 3);
	return (ret);
}
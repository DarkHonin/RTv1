/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:39:58 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/03 19:39:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

const char	*shape_get_name(t_shape_type t)
{
	static const char	*names[] = 
	{
		"SHAPE_LINE",
		"SHAPE_PLANE",
		"SHAPE_SPHERE",
		"SHAPE_CILINDER",
		"SHAPE_BOX",
		"SHAPE_LAMP",
		"SHAPE_CAMERA"
	};
	return (names[t]);
}
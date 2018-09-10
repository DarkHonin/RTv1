/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:13:33 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/30 10:18:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_stage	*get_stage()
{
	static t_stage STAGE;

	if (STAGE.camera.type != SHAPE_CAMERA)
	{
		STAGE.camera.type = SHAPE_CAMERA;
		STAGE.space = create_array(sizeof(t_shape));
	}
	return (&STAGE);
}
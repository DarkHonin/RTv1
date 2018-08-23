/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:13:33 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 11:17:12 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_stage	*get_stage()
{
	static t_stage STAGE;

	if (STAGE.camera.type != CAMERA)
	{
		STAGE.camera.type = CAMERA;
		ft_bzero(STAGE.camera.values[0], sizeof(int) * 3);
		ft_bzero(STAGE.camera.values[1], sizeof(int) * 3);
	}
	return (&STAGE);
}
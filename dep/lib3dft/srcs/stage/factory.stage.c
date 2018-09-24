/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.stage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 00:29:05 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/21 00:29:05 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_stage	*get_stage()
{
	static	t_stage *stage = NULL;

	if (stage != NULL)
		return (stage);
	stage = create_stage();
	return (stage);
}
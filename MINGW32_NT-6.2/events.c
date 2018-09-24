/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:38:07 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/17 09:38:07 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>

int	event_handle(void *e)
{
	return (1);
}

int key_event(int keycode, void *e)
{
	if (keycode == SDLK_ESCAPE)
		exit(1);
	return (1);
}
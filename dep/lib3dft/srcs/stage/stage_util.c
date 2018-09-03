/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 11:45:45 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/02 11:45:45 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

t_value_v	project_view_axis(t_value_v s, t_axis a)
{
	t_value_v ret;

	ret = create_value_v(2);
	ret[0] = s[ABS(a - 1)];
	ret[1] = s[(a + 1) % 3];
	return (ret);
}
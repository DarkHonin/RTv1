/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:25:32 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/24 11:25:32 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3dft.h>

void	space_set(t_space *s, t_space_c comp, t_value_v val)
{
	matrix_set_row(s->components, val, SPACE_COMPONENT_SIZE, comp);
	s->inverse = matrix_inverse(s->components, SPACE_COMPONENT_SIZE);
}
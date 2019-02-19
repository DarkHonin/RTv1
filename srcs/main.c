/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:34:42 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/31 11:16:36 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <stdio.h>
#include <math.h>


int	loop(void *arg)
{
	return (1);
}

int main(int ac, char **av)
{
	const t_node_v values[3] = {20, 0, 10};

	t_vect *v = point_c(3, values);
	for(int i = 0; i < v->values; i++)
		printf("%f ",v->nodes[i]);
}
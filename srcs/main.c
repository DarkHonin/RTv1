/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:34:42 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/21 14:36:11 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <stdio.h>

int main(int ac, char **av)
{
	t_shape *shapes;

	if (ac != 3)
		return (std_error("Insuficient arguments"));
	log_state("[main]\tProgram started", &main);
	log_state("[main]\tExpected shapes: ", &main);
	log_state(ft_strjoin("[main]\t\t", av[1]), &main);
	log_state("[main]\tShape file: ", &main);
	log_state(ft_strjoin("[main]\t\t", av[2]), &main);
	shapes = ft_memalloc(ft_atoi(av[1]) * sizeof(t_size));
}
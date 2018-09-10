/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:39:25 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/03 13:39:25 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_1.h>
#include <fcntl.h>

static t_value_v	parse_value(char *vals)
{
	char		**components;
	t_value_v	ret;
	t_len		i;

	i = 0;
	components = ft_strsplit(vals, ';');
	while (components[i])
	{
		append_to_value_v(&ret, i, ft_atoi(components[i]));
		free(components[i]);
		i++;
	}
	free(components);
	return (ret);
}

static void	parse_shape(char *data)
{
	char		**parts;
	char		**components;
	t_len		p;
	t_value_v	values;
	t_shape		hold;

	parts = ft_strsplit(data, '|');
	p = 0;
	while (p < 3)
	{
		values = parse_value(parts[p]);
		if (p == 2)
			vect_swap(&values, vect_devide(values, (t_vect3){360, 360, 360}, 3));
		shape_set(p, values, &hold);
		free(parts[p++]);
		free(values);
	}
	hold.type = ft_atoi(parts[3]);
	values = parse_value(parts[4]);
	hold.color[0] = values[0];
	hold.color[1] = values[1];
	hold.color[2] = values[2];
	free(values);
	free(parts[3]);
	free(parts[4]);
	free(parts);
	stage_add_space(hold);
}

void	read_shapes(char *file)
{
	int		f;
	char	*line;

	f = open(file, O_RDONLY);
	if (f < 0)
		return ;
	while (get_next_line(f, &line) > 0)
	{
		if (ft_charcnt(line, '|') == 4)
			parse_shape(line);
		free(line);
	}
	free(line);
}
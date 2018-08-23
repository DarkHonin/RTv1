/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:39:39 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 09:42:25 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utilft.h>

/*
**	The array requires a definition of the size of its elements.
*/

t_array	*create_array(t_len size)
{
	t_array *ret;

	ret = (t_array *)ft_memalloc(sizeof(t_array));
	ret->size = size;
	ret->len = 0;
	ret->items = ft_memalloc(size);
	return (ret);
}

void	free_array(t_array *ar)
{
	free(ar->items);
	free(ar);
}
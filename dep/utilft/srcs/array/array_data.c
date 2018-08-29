/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:43:08 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/23 10:03:39 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utilft.h>

/*
**	To push a value it requires a pointer to the data you wish to add
**	it will only copy the data from the pointer.
*/

int		array_push(t_array *ar, void *item)
{
	void	*holder;

	log_state(LOG, "[array_push]\tCreating new pointer", &array_push);
	holder = ft_memalloc((ar->len + 1) * ar->size);
	log_state(LOG, "[array_push]\tCopying original", &array_push);
	ft_memcpy(holder, ar->items, ar->len * ar->size);
	log_state(LOG, "[array_push]\tCreating new pointer", &array_push);
	ft_memcpy(holder + (ar->len * ar->size), item, ar->size);
	free(ar->items);
	ar->items = holder;
	ar->len++;
	return (ar->len);
}
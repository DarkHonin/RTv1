#include <rtv_1.h>

t_shape *closest_shape(t_space *s, t_shape *sh)
{
	size_t		count;
	t_node_v	dist;
	t_node_v	cdist;
	t_shape		*ret;

	count = 0;
	dist = -1;
	while(count < s->shape_count)
	{
		cdist = point_d(s->shapes[count]->origen, sh->origen);
		if (dist < 0)
		{
			dist = cdist;
			ret = s->shapes[count];
		}
		else
		{
			if (cdist < dist)
			{
				dist = cdist;
				ret = s->shapes[count];
			}
		}
		count++;
	}
	if(dist == -1)
		return (0);
	return (ret);
}

void	asign_direction(t_shape *ref, t_shape *new)
{

}

void	*space_a(t_space *space, t_shape *shape)
{
	t_shape	**store;
	t_shape	*closet;
	size_t	count;

	count = 0;
	closet = closest_shape(space, shape);
	store = (t_shape **)ft_memalloc(sizeof(t_shape *) * (space->shape_count + 1));
	ft_memcpy(store, space->shapes, sizeof(t_shape *) * (space->shape_count));
	store[space->shape_count] = shape;
	shape->index = space->shape_count;
	space->shape_count++;
	free(space->shapes);
	space->shapes = store;
	if(closet)
		asign_direction(closet, shape);
}
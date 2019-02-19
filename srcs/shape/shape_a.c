#include <rtv_1.h>

void	shape_a(t_shape *shape, t_vect *p)
{
	t_vect **store;

	store = (t_vect**)ft_memalloc(sizeof(t_vect *) * (shape->point_count + 1));
	ft_memcpy(store, shape->points, sizeof(t_vect *) * (shape->point_count));

	store[shape->point_count] = p;
	shape->point_count++;
	free(shape->points);
	shape->points = store;
}
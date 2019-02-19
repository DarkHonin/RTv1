#include <rtv_1.h>

t_space	*space_c(t_vect *bounds){
	t_space *ret;

	ret = (t_space *)ft_memalloc(sizeof(t_space));
	ret->bounds = bounds;
	ret->shapes = (t_shape **)ft_memalloc(sizeof(t_shape *));
	ret->shape_count = 0;
	return (ret);
}

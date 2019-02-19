#include <rtv_1.h>

t_space	*space_c(t_vect *bounds){
	t_space *ret;

	ret = (t_space *)ft_memalloc(sizeof(t_space));
	ret->bounds = bounds;
	return (ret);
}

#include <rtv_1.h>

t_shape	*shape_c(t_shape_e type)
{
	t_shape	*ret;

	ret = (t_shape *)ft_memalloc(sizeof(t_shape));
	ret->type = type;
	ret->origen = POINT_C(0);
	ret->rotation = POINT_C(0);
	ret->scale = POINT_C(1);
	ret->point_count = 0;
	return (ret);
}
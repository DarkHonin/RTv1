#include <3dft.h>

t_space	*create_space()
{
	t_space	*ret;
	t_value_m	point;

	ret = ft_memalloc(sizeof(t_space));
	ret->components = create_value_m(SPACE_COMPONENT_SIZE);
	matrix_init(ret->components, SPACE_COMPONENT_SIZE);
	ret->x_component = ret->components[0];
	ret->y_component = ret->components[1];
	ret->z_component = ret->components[2];
	ret->translation = ret->components[3];
	ret->parent = NULL;
	return (ret);
}

t_stage	*create_stage()
{
	t_stage *ret;

	ret = (t_stage *)ft_memalloc(sizeof(t_stage));
	ret->camera_space = create_space();
	ret->global_space = create_space();
	return (ret);
}
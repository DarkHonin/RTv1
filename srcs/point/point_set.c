#include <rtv_1.h>

void	point_set(t_vect *v, size_t i, t_node_v val)
{
	if (i >= v->values)
	{
		ft_putstr("point_set: Index out of range [");
		ft_putnbr(i);
		ft_putstr(" -> ");
		ft_putnbr(v->values);
		ft_putendl("]");
		exit(EXIT_FAILURE);
	}
	v->nodes[i] = val;
}
#include <rtv_1.h>

void	space_p(t_space *space)
{
	size_t	count;

	ft_putstr("Space: \n\tBound ");
	point_p(space->bounds);
	ft_putstr("\n\tShapes count: ");
	ft_putnbr(space->shape_count);
	ft_putstr("\n");
	count = 0;
	while (count < space->shape_count)
	{
		ft_putstr("\t\t");
		shape_p(space->shapes[count++]);
	}
}
#include <rtv_1.h>

void	shape_p(t_shape *shape)
{
	size_t	count;

	ft_putstr("Shape( type=");
	ft_putnbr(shape->type);
	ft_putstr(" point_count=");
	ft_putnbr(shape->point_count);
	ft_putstr("origen=");
	point_p(shape->origen);
	count = 0;
	ft_putstr(" points='");
	while(count < shape->point_count)
	{
		point_p(shape->points[count]);
		if (count < shape->point_count - 1)
			ft_putstr(", ");
		count++;
	}
	ft_putstr("' )\n");
}
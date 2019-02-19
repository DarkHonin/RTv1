#include <rtv_1.h>

void point_p(t_vect *point)
{
	size_t	count;

	count = 0;
	ft_putstr("[");
	while(count < point->values)
	{
		ft_putnbr(point->nodes[count]);
		if (count < point->values - 1)
			ft_putstr("; ");
		count++;
	}
	ft_putstr("]");
}
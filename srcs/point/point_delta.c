#include <rtv_1.h>

t_vect	*point_delta(t_vect *a, t_vect *b)
{
	size_t	count;
	t_vect	*ret;

	if (a->values != b->values){
		ft_putendl("Point delta invalid: a.values != b.values");
		exit(EXIT_FAILURE);
	}
	count = 0;
	ret = point_c(a->values, (void *)0);
	while (count < a->values)
	{
		point_set(ret, count, a->nodes[count] - b->nodes[count]);
		count++;
	}
	return (ret);
}
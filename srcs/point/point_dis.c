#include <rtv_1.h>

t_node_v	point_dis(t_vect *a, t_vect *b)
{
	t_node_v	dt;
	size_t		count;

	if (a->values != b->values)
	{
		ft_putendl("vect length missmatch");
		exit(EXIT_FAILURE);
	}

	dt = 0;
	count = 0;
	while (count < a->values)
	{
		dt += pow(a->nodes[count] - b->nodes[count], 2);
		count++;
	}

	return (sqrt(dt));
}
#include <rtv_1.h>

t_shape *closest_shape(t_space *s, t_shape *sh)
{
	size_t		count;
	t_node_v	dist;
	t_node_v	cdist;
	t_shape		*ret;

	count = 0;
	dist = -1;
	while(count < s->shape_count)
	{
		cdist = point_dis(s->shapes[count]->origen, sh->origen);
		if (dist < 0)
		{
			dist = cdist;
			ret = s->shapes[count];
		}
		else
		{
			if (cdist < dist)
			{
				dist = cdist;
				ret = s->shapes[count];
			}
		}
		count++;
	}
	if(dist == -1)
		return (0);
	return (ret);
}

void print_int_bytes(int q)
{
	unsigned char *qq = (unsigned char *)&q;
	for (int i = 0; i < sizeof(int); i++)
		if(qq[i])
			printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(qq[i]));
	printf("\n");
}

void	asign_direction(t_shape *ref, t_shape *new)
{
	double			*degs;
	const double	mark = M_PI / 4;
	char			ns;
	double			eq;

	degs = point_dir(ref->origen, new->origen);
	ns = degs[0] < 0;
	if(ns)
		degs[0] *= -1;
	eq = (fabs(degs[0] - mark) < 0.01) | (fabs(degs[0] - (M_PI - mark)) < 0.01);

	if (degs[0] <= mark || degs[0] >= M_PI - mark || eq){
		printf("%s ", (degs[0] <= mark ? "North" : "South"));
		print_int_bytes((degs[0] <= mark ? NORTH : SOUTH));
	}
	if ((degs[0] > mark && degs[0] < M_PI - mark) || eq){
		printf("%s\n", (ns ? "East" : "West"));
	}
	printf("xy: %f\n", degs[0]);
	printf("xz: %f\n\n", degs[1]);
}

void	*space_a(t_space *space, t_shape *shape)
{
	t_shape	**store;
	t_shape	*closet;
	size_t	count;

	count = 0;
	closet = closest_shape(space, shape);
	store = (t_shape **)ft_memalloc(sizeof(t_shape *) * (space->shape_count + 1));
	ft_memcpy(store, space->shapes, sizeof(t_shape *) * (space->shape_count));
	store[space->shape_count] = shape;
	shape->index = space->shape_count;
	space->shape_count++;
	free(space->shapes);
	space->shapes = store;
	if(closet)
		asign_direction(closet, shape);
}
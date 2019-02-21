#include <rtv_1.h>
#include <math.h>

double *point_dir(t_vect *zero, t_vect *point)
{
	float		yx;
	float		zx;
	t_vect		*local;
	double		*ret;

	local = point_delta(point, zero);
	point_p(local);
	yx = atanf(local->nodes[1] / (local->nodes[0] == 0 ? 1 : local->nodes[0]));
	zx = atanf(local->nodes[2] / (local->nodes[0] == 0 ? 1 : local->nodes[0]));
	ret = (double *)ft_memalloc(sizeof(double) * 2);
	ret[0] = yx;
	ret[1] = zx;

	free(local->nodes);
	free(local);

	return (ret);
}
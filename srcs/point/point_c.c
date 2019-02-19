#include <rtv_1.h>

t_vect	*point_c(size_t len, const t_node_v *values){
	t_vect	*ret;
	size_t	count;

	ret = (t_vect*)ft_memalloc(sizeof(t_vect));
	ret->nodes = (t_node_v *)ft_memalloc(len * sizeof(t_node_v));
	ret->values = len;
	
	count = 0;
	while(count < len){
		ret->nodes[count] = values[count];
		count++;
	}

	return (ret);
}
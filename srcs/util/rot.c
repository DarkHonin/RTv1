#include <rtv_1.h>

unsigned char	rot(unsigned char q)
{
	unsigned char high;
	unsigned char ret;
	unsigned char a;
	unsigned char b;

	high = hob(q);
	printf("%s :: High: %d\n", ft_itoa_b(q, 2), high);
	a = q << high;
	b = q >> (8 - high);
	ret = (a | b);
	printf("%s :: \n", ft_itoa_b(ret, 2));
	return (ret);
}
#include <rtv_1.h>

unsigned char	hob (unsigned char byte)
{
	unsigned char q;

	while(q < 8)
	{
		//printf("~%d %f %ui\n", q, pow(2, 8 - q), byte);
		if ((int)pow(2, 8 - q) <= byte)
			return (q);
		q++;
	}
    return (-1);
}
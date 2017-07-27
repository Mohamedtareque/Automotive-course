#include "dio.h"
void init_dio_pin(OBJDIO_t *obj)
{
	if (obj->base == BASE_A || obj->base == BASE_B || obj->base == BASE_C || obj->base == BASE_D)
	{
		if (obj->dir == OUTPUT)
		{
			SET_REG8_BIT(obj->base + DIR_OFFSET,obj->pin);
		}else
		{
			CLEAR_REG8_BIT(obj->base + DIR_OFFSET,obj->pin );
		}
	}
}

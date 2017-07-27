// here we creat pinMode function 
// this function takes two arguments 
// first one is PORT** ==> PORTA0 or PA0 
//second one is OUTPUT OR INPUT 
void pinMode(uint8_t pin, Obj *obj)
{
	if (pin>=33 && pin<=40)
	{
		obj->base = BASE_A ;
		if (obj->dir == OUTPUT )
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) |= (1<<(40-pin));
		}else if (obj->dir == INPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) &=~ (1<<(40-pin));
		}
	}else if (pin>=1 && pin<=8)
	{
		obj->base = BASE_B ;
		if (obj->dir == OUTPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) |= (1<<(pin));
		}else if (obj->dir == INPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) &=~ (1<<(pin));
		}
	}else if (pin>=14 && pin<=21)
	{
		obj->base = BASE_D ;
		if (obj->dir == OUTPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) |= (1<<(21-pin));
		}else if (obj->dir == INPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) &=~ (1<<(21-pin));
		}
	}else if (pin>=22 && pin<=29)
	{
		obj->base = BASE_C ;
		if (obj->dir == OUTPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) |= (1<<(29-in));
		}else if (obj->dir == INPUT)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_DIR ) &=~ (1<<(29-pin));
		}
	}
}

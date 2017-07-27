//digitalWrite function

void digitalWrite(uint8_t pin,Obj* obj)
{
	if (pin>=33 && pin<=40)
	{
		obj->base = BASE_A ;
		if (obj->state == HIGH)
		{
			*(volatile uint8_t*)(obj->base + OFFSET_PORT) |= 1<<(40-pin);
		}else if(obj->state == LOW)
		{
			*(volatile uint8_t*)(obj->base + OFFSET_PORT) &=~ 1<<(40-pin);
		}
	}else if (pin>=1 && pin<=8)
		{
		obj->base = BASE_B ;
		if (obj->state == HIGH)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_PORT ) |= (1<<(pin));
		}else if(obj->state == LOW)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_PORT ) &=~ (1<<(pin));
	}else if (pin>=14 && pin<=21)
		{
		obj->base = BASE_D ;
		if (obj->state == HIGH)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_PORT ) |= (1<<(21-pin));
		}else if(obj->state == LOW)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_PORT ) &=~ (1<<(21-pin));
		}
	}else if (pin>=22 && pin<=29)
		{
		obj->base = BASE_C ;
		if (obj->state == HIGH)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_PORT ) |= (1<<(29-pin));
		}else if(obj->state == LOW)
		{
			*(volatile uint8_t*) (obj->base + OFFSET_PORT ) &=~ (1<<(29-pin));
	}
	}
}

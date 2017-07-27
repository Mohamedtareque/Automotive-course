typedef unsigned char uint8_t ;
typedef unsigned int uint16_t ;

typedef enum boolean
{
	FALSE = 0 , TRUE = 1 ;
}Boolean;

typedef enum state
{
	INPUT = 0 , OUTPUT = 1 ;
}State;

typedef enum booleanstate
{
	LOW = 0 , HIGH = 1 ;
}booleanState;

typedef struct obj
{
	State dir ;
	uint8_t pin ;
	uint8_t base ;
	booleanstate state;
}Obj;


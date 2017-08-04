void timer0_init()
{
  TCCNT |=(1<<CS00);
  TCNT0 = 0;
}
void main()
{
  DDRC |=1<<0x01; 
  timer0_init() ;
  while(1)
  {
    if(TCNT >= 124)
    {
       PORTC ^=(1<<0x01);
       TCNT0=0;
    }
  }
}


void timer0_init()
{
  TCNT0 = 0;
  TCCR0 |=0x05;
}
void main()
{
  DDRC |=0x01;
  timer0_init();
  while(1)
  {
    if(TCNT>=124)
    {
      PORTC ^=0x01;
      TCNT =0 ;
     }
  }
}

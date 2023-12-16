#include <16f887.h>
#use delay(clock=20m)
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8,parity=N, ERRORS)
#include "flex_lcdb.c"
void forward()
{
output_high(pin_d0);
output_low(pin_d1);
output_high(pin_d2);
output_low(pin_d3);
delay_ms(1000);
printf("1");
delay_ms(100);
}
void reverse()
{
output_low(pin_d0);
output_high(pin_d1);
output_low(pin_d2);
output_high(pin_d3);
delay_ms(1000);
printf("2");
delay_ms(100);
}
void right()
{
output_high(pin_d0);
output_low(pin_d1);
output_low(pin_d2);
output_high(pin_d3);
delay_ms(1000);
printf("3");
delay_ms(100);
}
void left()
{
output_low(pin_d0);
output_high(pin_d1);
output_high(pin_d2);
output_low(pin_d3);
delay_ms(1000);
printf("4");
delay_ms(100);
}



void drill()
{
output_low(pin_d4);
delay_ms(1000);
printf("5");
delay_ms(100);
}
void seed_shower()
{
output_low(pin_e0);
delay_ms(200);
output_high(pin_e0);
delay_ms(1500);
output_low(pin_e1);
delay_ms(200);
output_high(pin_e1);
delay_ms(1500);
printf("7");
output_high(pin_e0);
output_high(pin_e1);
delay_ms(1000);
}
void pump()
{
output_low(pin_d5);
delay_ms(1000);
printf("6");
delay_ms(100);
}
void level()
{
output_low(pin_a0);
delay_ms(200);
output_high(pin_a0);
delay_ms(1500);
output_low(pin_a1);
delay_ms(200);
output_high(pin_a1);
delay_ms(1500);
printf("9");
output_high(pin_a0);
output_high(pin_a1);
delay_ms(1000);
}
void main()
{
enable_interrupts(int_rda);
enable_interrupts(global);
//setup_adc(ADC_CLOCK_INTERNAL); // initialize ADC with a sampling rate of Crystal/4 MHz
//setup_adc_ports(sAN0);   // set PIN_A0 as analog input channel
lcd_init();
delay_ms(100);
printf(lcd_putc,"\fSWARM AGRI \n  ROBOT ");
delay_ms(1000);
output_low(pin_d0);
output_low(pin_d1);
output_low(pin_d2);
output_low(pin_d3);

output_high(pin_d4);
output_high(pin_d5);
output_high(pin_e0);
output_high(pin_e1);
output_high(pin_a0);
output_high(pin_a1);
while(1)
{
/// Input Pins nodemcu - pic c0,c1,c2,c3,c4,c5,d7 ///
/// 1 - forward  2 - reverse 3 - right 4 - left 5 - drill  6 - pump  7 - seed shower
if(input(pin_c0))
{
printf(lcd_putc,"\fForward");
delay_ms(1000);
forward();
}
else if(input(pin_c1))  
{
printf(lcd_putc,"\fReverse");
delay_ms(1000);
reverse();
}
else if(input(pin_c2))
{
printf(lcd_putc,"\fRight");
delay_ms(1000);
right();
}
else if(input(pin_c3))
{
printf(lcd_putc,"\fLeft");
delay_ms(1000);
left();
}
else if(input(pin_c4))
{
printf(lcd_putc,"\fDrill");
delay_ms(1000);
drill();
}
else if(input(pin_c5))
{
printf(lcd_putc,"\fPump");
delay_ms(1000);
pump();
}
else if(input(pin_d7))
{
printf(lcd_putc,"\fSeed Plot");
delay_ms(1000);
seed_shower();
}
else if(input(pin_d6))
{
printf(lcd_putc,"\fLeveling");
delay_ms(1000);
level();
}else
{
output_low(pin_d0);
output_low(pin_d1);
output_low(pin_d2);
output_low(pin_d3);
output_high(pin_d4);
output_high(pin_d5);
output_high(pin_e0);
output_high(pin_e1);
output_high(pin_a0);
output_high(pin_a1);
printf("8");
printf(lcd_putc,"\fSwarmAgribot \nWelcomes You ");
delay_ms(100);

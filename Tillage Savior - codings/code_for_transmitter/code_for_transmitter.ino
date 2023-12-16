#include <16f877a.h>
#use delay(clock=20m) 
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8,parity=N, ERRORS)
#include "flex_lcdb.c" 
float c,v,p;
int16 u=0,co=0,d=0,t=0;
int16 x=0;
void main() 
{ 
setup_adc(ADC_CLOCK_INTERNAL); // initialize ADC with a sampling rate of Crystal/4 MHz
setup_adc_ports(ALL_ANALOG);   // set PIN_A0 as analog input channel    
lcd_init();   
delay_ms(100);  
output_low(pin_d0);
printf(lcd_putc,"\f ENERGY PREDICTION \nDEMAND CONTROL"); // print value on LCD
delay_ms(2500);  
while(1) // infinite loop 
{ 
d=d+1;
x=x+1;
set_adc_channel(0); 
delay_ms(100);  
v = read_adc(); 
delay_ms(100);    // capture current temperature reading
v =(v/1023)*5;    
delay_ms(100); 
v=v*52;
set_adc_channel(1); 
delay_ms(100);  
c = read_adc(); 
delay_ms(100);    // capture current temperature reading
c=(c/1023)*5;    
delay_ms(100); 
p=c*v;
if((c>0.1)&&(c<0.3))
{
u=u+1;
co=u*0.5;
}
if(c>0.3)
{
u=u+2;
co=u*1;
}
printf(lcd_putc,"\fC:%f V:%f ",c,v); 
printf(lcd_putc,"\n  P:%f ",p);// print value on LCD
delay_ms(1500);  
printf(lcd_putc,"\fU:%ld co:%ld ",u,co); 
printf(lcd_putc,"\n Day:%ld ",d);// print value on LCD
delay_ms(1500);  
if(x==1)
{
printf("\f%f,%f",c,v);
delay_ms(200); 
}
if(x==2)
{
printf("\f%f*%ld",p,u);
delay_ms(200); 
}
if(x==3)
{
printf("\f%ld#%ld",co,t);
delay_ms(200); 
x=0;
}
if(d>=30)
{
d=0;
printf(lcd_putc,"\nEND OF MONTH.....");// print value on LCD
delay_ms(1500);  
u=0;
d=0;
co=0;
}
}
}
